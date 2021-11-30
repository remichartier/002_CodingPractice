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
    xor_sum = None
    for length in range(1,len(arr)+1):
        #print(f'length = {length}')
        for i in range(len(arr) +1 -length):
            #print(f'i = {i}, sub_array = arr[{i},{i+length}] ')
            sub_array = arr[i:i+length]
            #print(f'sub_array = {sub_array}')
            # Calculate sum of subarray
            sum_xor_subarray = sub_array[0]
            for j in range(1,len(sub_array)):
                sum_xor_subarray ^= sub_array[j]
            if xor_sum == None:
                xor_sum = sum_xor_subarray
            else:
                xor_sum ^= sum_xor_subarray
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
