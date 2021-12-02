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
    BOB = 0
    ANDY = 1
    player = 0
    max_index = len(arr)
    while max_index != 0:
        max_index = arr.index(max(arr[:max_index]))
        player = 0 if player == 1 else 1
        
    if player == BOB:
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
