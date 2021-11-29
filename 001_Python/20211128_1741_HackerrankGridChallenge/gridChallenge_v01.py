#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gridChallenge' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING_ARRAY grid as parameter.
#

def gridChallenge(grid):
    # Write your code here
    output = []
    for s in grid:
        s2 = sorted(s)
        str2 = ''.join(s2)
        output.append(str2)
    # Now need to check if columns are in alphabetical orders.
    for c in range(len(output[0])):
        for r in range(1,len(output)):
            if output[r-1][c] > output[r][c]:
                return "NO"
    return "YES"
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        grid = []

        for _ in range(n):
            grid_item = input()
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
