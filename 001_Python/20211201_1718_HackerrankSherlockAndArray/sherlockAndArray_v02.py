#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'balancedSums' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def balancedSums(arr):
    # Write your code here
        # Write your code here
    left = 0
    right = sum(arr[1:])
    if left == right:
        return 'YES'
    for i in range(1,len(arr)):
        left += arr[i-1]
        right -= arr[i] 
        if left == right:
            return 'YES'
    return 'NO'
    
    '''
    7 Test Cases Passed out of 7 Test Cases
    '''


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = balancedSums(arr)

        fptr.write(result + '\n')

    fptr.close()