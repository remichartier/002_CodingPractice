#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'missingNumbers' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER_ARRAY brr
#

def missingNumbers(arr, brr):
    # Write your code here
    missing = []
    i = 0
    arr.sort()
    brr.sort()
    
    while i < len(brr) and brr[i] <= arr[-1]: 
        if(brr[i] not in missing):
            count_in_brr = brr.count(brr[i])
            count_in_arr = arr.count(brr[i])
            if count_in_brr > count_in_arr:
                missing.append(brr[i])
        i += 1
    if i < len(brr) and  brr[i] > arr[-1]:
        missing.extend(list(set(brr[i:])))
    return missing
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    m = int(input().strip())

    brr = list(map(int, input().rstrip().split()))

    result = missingNumbers(arr, brr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
