#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    # Write your code here
    countValleys = 0
    height = 0
    UP = 'U'
    DOWN = 'D'
    # need to count height transitions from -1 to 0,
    # ie if height == -1 and s == UP
    for p in path:
        if p == UP:
            if height == -1:
                countValleys += 1
            height += 1
        if p == DOWN:
            height -= 1
    return countValleys
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
