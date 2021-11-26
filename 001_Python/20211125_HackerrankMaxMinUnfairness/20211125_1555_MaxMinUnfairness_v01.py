#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maxMin' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#

def maxMin(k, arr):
    # Write your code here
    arr.sort()
    result = []
    unfairness = arr[-1] - arr[0]
    for i in range(len(arr)-(k - 1)):
        sub_arr = arr[i:i+k]
        score = arr[i+k-1] - arr[i]
        if score < unfairness:
            result = sub_arr
            unfairness = score
    return unfairness

    ''' Passed 9 tests out of 10 : 
    Compiler Message
Time limit exceeded
Your code did not execute within the time limits. Please optimize your code. For more information on execution time limits, refer to the environment page
'''

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    k = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = maxMin(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
