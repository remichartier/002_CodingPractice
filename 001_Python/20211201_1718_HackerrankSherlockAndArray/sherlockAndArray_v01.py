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
    for i in range(len(arr)):
        left = sum(arr[:i])
        right = sum(arr[i+1:])
        '''
        left = 0
        right = 0
        if i == 0:
            left = 0
            right = arr[i+1:]
        elif i == len(arr) -1:
            right = 0
            left = arr[:i-1]
        else:
            left = arr[:i]
            right = arr[i+1:]
        '''
        if left == right:
            return 'YES'
    return 'NO'
    
    '''
    Terminated due to timeout :(
    Compiler Message
Time limit exceeded
Your code did not execute within the time limits. 
Please optimize your code. For more information on execution time limits, 
refer to the environment page
2 Test Cases out of 7 Test Cases
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