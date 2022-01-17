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

# Solutions found by other programmers (https://www.hackerrank.com/amirfar987)

def bomberMan(n, grid):
    # Write your code here
    # Build alternative grid to store at which time stamp the bombs are placed
    # and keep status of bombs.
  
def flipped(g):
    grid = g.copy()
    m = len(grid)
    n = len(grid[0])
    fgrid = []
    for i in range(m):
        raw = ''
        for j in range(n):
            if grid[i][j] == 'O' \
            or grid[i][j] == '*' \
            or (i-1 >=0 and grid[i-1][j] == 'O')    \
            or (i+1 < m and grid[i+1][j] == 'O')    \
            or (j-1 >=0 and grid[i][j-1] == 'O')    \
            or (j+1 < n and grid[i][j+1] == 'O')    :
                raw += '*'
            else:
                raw += '.'
        fgrid.append(raw)
    dgrid = []
    for i in range(m):
        raw = ''
        for j in range(n):
            raw += '.' if fgrid[i][j] == '*' else 'O'
        dgrid.append(raw)
    return dgrid
def plant_all(g):
    grid = g.copy()
    m = len(grid)
    n = len(grid[0])
    for i in range(m):
        grid[i] = 'O'*n
    return grid
def bomberMan(n, grid):
    if (n==1) : return grid
    if (n-1) % 4 == 0: return flipped(flipped(grid))
    if n % 2 ==0 : return plant_all(grid)    
    return flipped(grid)


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
