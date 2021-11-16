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
    a.sort()
    b = []
    for i in range(len(a)):
        b =[a[i]]
        for j in range(i+1, len(a)):
            if a[j] - b[0] <= 1:
                b.append(a[j])
        longest = max(longest,len(b))
    return longest


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
