#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'cookies' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY A
#

def cookies(k, A):
        # Write your code here
    if len(A) <2:
        return -1
    count = 0
    while (len(A) > 1) and min(A) < k:
        count += 1
        min1 = min(A)
        A.remove(min1)
        min2 = min(A)
        A.remove(min2)
        A.append(min1 + 2*min2)   
    if min(A) >= k:
        return count
    return -1
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    A = list(map(int, input().rstrip().split()))

    result = cookies(k, A)

    fptr.write(str(result) + '\n')

    fptr.close()
