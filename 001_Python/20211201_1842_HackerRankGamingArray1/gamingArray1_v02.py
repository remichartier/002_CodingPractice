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
    # Write your code here
    # Write your code here
    BOB = 0
    ANDY = 1
    player = 1
    while len(arr) != 0:
        player = (player + 1) % 2
        max_index = arr.index(max(arr))
        #arr = arr[:max_index]
        i = len(arr) -1
        while(i != max_index-1):
            arr.pop(i)
            i -=1
    if player == BOB:
        return 'BOB'
    else:
        return 'ANDY'

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
