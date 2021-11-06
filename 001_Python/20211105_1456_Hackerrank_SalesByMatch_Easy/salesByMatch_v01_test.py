#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sockMerchant' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY ar
#

def sockMerchant(n, ar):
    # Write your code here
    count = 0
    ar.sort()
    i = 0
    while i +1 < len(ar):
        if ar[i] == ar[i+1]:
            count +=1
            i += 2
        else:
            i += 1
    return count

print(sockMerchant(7,[1,2,1,2,1,3,2]))
print(sockMerchant(7,[10, 20, 20, 10, 10, 30, 50, 10, 20]))
'''
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
'''
