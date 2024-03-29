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
    if len(A) == 0:
        return -1;
    if min(A) >= k:
        return 0;
    count = 0
    heapq.heapify(A)
    while len(A) > 1 and A[0] < k:
        min1 = heapq.heappop(A)
        min2 = heapq.heappop(A)
        heapq.heappush(A, min1 + 2 * min2)
        count += 1
    if A[0] >= k:
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
