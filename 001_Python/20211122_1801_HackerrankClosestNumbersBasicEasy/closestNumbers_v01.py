#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'closestNumbers' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def closestNumbers(arr):
    # Write your code here
    # Algo : 
    # 1. sort array.
    # min = arr[len(arr)-1] - arr[0]
    # 2. scroll array, if arr[i+1] - array[i] < min
    #   2.1 min becomes = arr[i+1] - array[i]
    #   2.1 empty output array
    #   2.2 add the 2 numbers in final list.
    # 2. if arr[i-1] - arr[i] == min
    #   2.1 add arr[i] and arr[i+1] to final list
    
    result = []
    arr.sort()
    #print(f'arr sorted : {arr}')
    min_diff = arr[-1] - arr[0]
    #print(f'min_diff : {min_diff}')
    for i in range(0,len(arr)-1):
        diff = arr[i+1] - arr[i]
        #print(f'diff : {diff}, min_diff : {min_diff}')
        if diff < min_diff:
            #print('Enter if diff < min_diff')
            min_diff = diff
            #print(f'diff : {diff}, min_diff : {min_diff}')
            result.clear()
            result.extend(arr[i:i+2])
        elif diff == min_diff:
                result.extend(arr[i:i+2])
        #print(f'min_diff = {min_diff}, result : {result}')
    return result

    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = closestNumbers(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
