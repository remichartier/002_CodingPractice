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

# Solutions found by other programmers (https://www.hackerrank.com/weilun_x)

def bomberMan(n, grid):
    # Write your code here
    # Build alternative grid to store at which time stamp the bombs are placed
    # and keep status of bombs.
  
    if n==0:                         
        return(grid)                    #if n=0, return the original grid
    
    x='O'*len(grid[0])
    array=[]
    for i in range(len(grid)):
        array.append(x)
    if n%2==0:
        return(array)                   #if n is even, return a grid full of 'O'
    
    def once(grid):                     #this is a function which iterate the pattern 'once'
        x='O'*len(grid[0])
        array=[]
        for i in range(len(grid)):
            array.append(list(x))          #first create a grid full of 'O'
        A=(0,1,-1,0, 0)
        B=(0,0,0, 1,-1)
        for i in range(len(grid)):
            for j in range(len(grid[0])):         #Then scan the input grid, find the first batch of 'O',        
                if grid[i][j]=='O':
                    for a,b in zip(A,B):
                        print(a,b)
                        try:
                            array[abs(i+a)][abs(j+b)]='.'
                        except:
                            pass                # Then detonate it and its surrounding to '.'   
        answer=[]
        for m in array:
            answer.append(''.join(m))                   #join the array back into a list and append to answer
        return(answer)
    
    n//=2                      #This parts figure out how many iteration it should do when n is large
    for q in range(n%12):          #so I notice the pattern repeats either every 2 iteration, or 3
        grid=once(grid)            #iternations, or 4. The least common number thing is 12, hence n%12
    return(grid)


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
