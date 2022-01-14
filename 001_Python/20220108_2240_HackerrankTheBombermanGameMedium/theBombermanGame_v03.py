#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'bomberMan' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING_ARRAY grid
#

''' Code passed on 2 initial test cases.
    But failed on 12 out of 12+14 = 26 Test Cases
    Terminated due to timeout :(
        Compiler Message
        Time limit exceeded
        Your code did not execute within the time limits. Please optimize your code. For more information on execution time limits, refer to the environment page
'''
'''
SUGGESTION FOR OPTIMIZING : 
- INSTEAD OF ALT_GRID
  - USE GRID, MARK INITIAL BOMBS AS B (STRING REPLACE 'O' BY 'B')
  - NOTE THEIR POSITIONS
  - REPLACE BLAST POSITIONS I+-1,J AND I,J+-1 BY 'D'
  - WHEN BOMBERMAN PLANT BOMBS IN ALL CELLS WITHOUT BOMBS, JUST STRING REPLACE '.' BY '0'
  - EVERY T+3 SECONDS, STRING REPLACE 'D' AND 'B' BY '.'
    - AND STRING REPLACE 'O' BY 'B' +
        - NOTE THEIR POSITIONS
        - REPLACE BLAST POSITIONS I+-1,J AND I,J+-1 BY 'D'
        
==> THIS PROVIDES OPTIMIZATION BY NOT LOOPING ON EACH LINE AND EACH COLUMN, AND BY JUST USING STRING OPERATIONS AS MUCH AS POSSIBLE...

OR NEED TO READ THE COMMENTS TO CHECK HOW THE OTHERS DID ...

'''
def Bomberman_plants_bombs_in_all_cells_without_bombs(t, grid):
    # - WHEN BOMBERMAN PLANT BOMBS IN ALL CELLS WITHOUT BOMBS, JUST STRING REPLACE '.' BY '0'
    alt_grid = []
    for s in grid:
        #print(f's = {s}')
        s = s.replace(".", "O")
        #print(f's after replacing . by O = {s}')
        alt_grid.append(s)
    return alt_grid

def bombs_planted_exactly_three_seconds_ago_will_detonate(t, grid):
    # Once a bomb detonates, it's destroyed along with anything in its four neighboring cells. This means that if a bomb detonates in cell i,j, any valid cells(i +- 1,j)and(i, j+-1)are cleared. If there is a bomb in a neighboring cell, the neighboring bomb is destroyed without detonating, so there's no chain reaction.
    # Here need to convert grid into array
    ##################################################
    alt_grid = []
    for line in grid:
        l = list(line)
        alt_grid.append(l) 
    grid = alt_grid
    
    for line in range(len(grid)):
        for col in range(len(grid[line])):
            if grid[line][col] == 'B':
                grid[line][col] = '.'
                # destroy all bombs around except if exploding at that time as well
                # ie except if 'B'
                if col - 1 >= 0:
                    if grid[line][col - 1] != 'B':
                        grid[line][col - 1] = '.'
                if col + 1 < len(grid[line]):
                    if grid[line][col + 1] != 'B':
                        grid[line][col + 1] = '.'
                if line - 1 >= 0:
                    if grid[line - 1][col] != 'B':
                        grid[line - 1][col] = '.'
                if line + 1 < len(grid):
                    if grid[line + 1][col] != 'B':
                        grid[line + 1][col] = '.'
    # Here need to convert back array into array of strings !!!!!
    ##############################################################
    alt_grid = []
    for l in grid:
        s = ''.join(l)
        alt_grid.append(s)
    grid = alt_grid        
    
    alt_grid = []
    for s in grid:
        s = s.replace('O','B')
        alt_grid.append(s) 
    return alt_grid

def convert_alt_grid(alt_grid):
    grid_result = []
    for s in alt_grid:
        s = s.replace('B','O')
        grid_result.append(s)  
    #print(f'alt_grid = {alt_grid}')                         
    #print(f'grid_result = {grid_result}')                         
    return grid_result

def bomberMan(n, grid):
    # Write your code here
    # Build alternative grid to store at which time stamp the bombs are placed
    # and keep status of bombs.
    print(f'n = {n}')
    nbrows = len(grid)
    nbcolumns = len(grid[0])
    # - USE GRID, MARK INITIAL BOMBS AS B (STRING REPLACE 'O' BY 'B')   
    alt_grid = []
    for s in grid:
        s = s.replace('O','B')
        alt_grid.append(s)
    #print(f'First step : grid = {grid}, alt_grid = {alt_grid}')
    #- NOTE THEIR POSITIONS
    
    #print(alt_grid)
    t = 0 # initial state
    if t == n:
        return convert_alt_grid(alt_grid)
    t += 1 # ie t = 1
    # After one second, Bomberman does nothing.
    if t == n:
        return convert_alt_grid(alt_grid)

    while t < n:
        t += 1 # ie t = 2
        # After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. No bombs detonate at this point.
        alt_grid = Bomberman_plants_bombs_in_all_cells_without_bombs(t, alt_grid)
        #print(f'Bomb man plants bombs in all cells --> alt_grid = {alt_grid}')
        if t >= n:
            break
        t += 1 # ie t = 3
        # After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
        alt_grid = bombs_planted_exactly_three_seconds_ago_will_detonate(t, alt_grid)
    
    # Here, stopped due to t == n
    # Need to translate back alt_grid into grid and then return grid
    return convert_alt_grid(alt_grid)    
'''
t=0 plant bombs
t=1 does nothing
t=2 plant bombs in all cells --> will explode at t=2 + 3 = 5
t=3 initial bombs explode (t = 0 + 3 = 3)
t=4 repeat step 3 (Bomberman plants bombs in all cells) --> will explode t=4+3=7
t=5 repeat step 4 : any bombs planted 3 seconds ago explode
t=6 repeat step 3 (Bomberman plants bombs in all cells) --> will explode t=6+3=9
t=7 repeat step 4 : any bombs planted 3 seconds ago explode
t=8 repeat step 3 (Bomberman plants bombs in all cells) --> will explode t=8+3=11
'''
'''
Debug
Input (stdin)

Download
6 7 3
.......
...B...
....B..
.......
BB.....
BB.....

0000000
000B000
0000B00
0000000
BB00000
BB00000

000.000
00...00
000...0
0000.00
BB00000
BB00000
'''


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    r = int(first_multiple_input[0])

    c = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    grid = []

    for _ in range(r):
        grid_item = input()
        grid.append(grid_item)

    result = bomberMan(n, grid)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
