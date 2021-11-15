#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    # Write your code here
    # 1. elements 1st array are all factors of integer being considered
    # 2. integer being considered is a factor of all elements of the 2nd array.
    max_elem = max(b)
    min_elem = max(a)
    count = 0
    for integer in range(min_elem,max_elem + 1):
        consider_elem = True
        for i in a:
            if integer%i != 0:
                consider_elem = False
                break;
        if not consider_elem:
            continue
        for i in b:
            if i%integer != 0:
                consider_elem = False
                break;
        # here, integer passed all the tests --> count it.
        if consider_elem:
            count += 1
    return count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()