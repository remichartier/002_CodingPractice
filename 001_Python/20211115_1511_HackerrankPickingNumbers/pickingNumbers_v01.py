#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pickingNumbers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def pickingNumbers(a):
    # Write your code here
    longest = 0
    curr_l = 1
    if len(a)<2:
        return len(a)
    for i in range(1,len(a)):
        if abs(a[i] - a[i-1]) <= 1:
            curr_l += 1
        else:
            longest = max(curr_l, longest)
            curr_l = 1
    return longest
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
