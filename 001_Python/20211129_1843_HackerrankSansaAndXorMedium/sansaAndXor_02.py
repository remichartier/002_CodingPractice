#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sansaXor' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def sansaXor(arr):
    # Write your code here
    '''
    Subarray    Operation    Result
    3        None        3
    4        None        4
    5        None        5
    3,4        3 XOR 4        7
    4,5        4 XOR 5        1
    3,4,5        3 XOR 4 XOR 5    2
    '''
    '''
    With using observation : 
    every array with an even number of elements results in 0 
    because each element appears even number of times

    every array with an odd number of elements results in XORing 
    the values at odd indices because, again, even-indexed elements 
    show up even number of times
    '''

    xor_sum = arr[0]
    if len(arr) % 2 == 0:
        return 0
    # otherwise calculate XOR sum of odd indices
    for i in range(2,len(arr),2):
        xor_sum ^= arr[i]
    return xor_sum

    '''
    Passing first 2 tests.
    But
    Compiler Message
    Time limit exceeded
    Your code did not execute within the time limits.
    Please optimize your code. For more information on execution time limits, 
    refer to the environment page
    '''    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = sansaXor(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
