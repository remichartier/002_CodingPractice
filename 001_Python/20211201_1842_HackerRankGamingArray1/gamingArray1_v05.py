#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gamingArray' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def gamingArray(arr):
    # Write your code here
    '''Simple C++ solution: Solution is based on the fact that the total numbers 
    of moves will be the number of strictly increasing elements found while iterating
     through the array once. Now Bob starts first and moves are made alternatingly. 
     So for 3 moves we have Bob, Andy, Bob, so bob wins. Similarly for 4 moves we have
      Bob, Andy, Bob, Andy, so andy wins.'''
    maximum = 0
    count = 0
    for i in range(0,len(arr)):
        if arr[i] > maximum:
            maximum = arr[i]
            count += 1
    if count % 2 == 0:
        return 'ANDY'
    else:
        return 'BOB'
        

    '''but some test cases not passing due to Time limit exceeded
Your code did not execute within the time limits. Please optimize your code. 
For more information on execution time limits, refer to the environment page
	'''


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(input().strip())

    for g_itr in range(g):
        arr_count = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = gamingArray(arr)

        fptr.write(result + '\n')

    fptr.close()
