#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'fibonacciModified' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER t1
#  2. INTEGER t2
#  3. INTEGER n
#

# t1, t2, t3
def fibonacciModified(t1, t2, n):
    # Write your code here
    t3 = t1 + (t2*t2)
    for i in range(4,n+1):
        t1 = t2
        t2 = t3
        t3 = t1 + (t2*t2)
    return t3


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    t1 = int(first_multiple_input[0])

    t2 = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()