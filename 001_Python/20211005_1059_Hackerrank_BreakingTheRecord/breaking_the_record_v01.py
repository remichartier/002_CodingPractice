#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    # Write your code here
    MOST = 0
    LEAST = 1
    most_least = [0,0] 
    min = 0
    max = 0
    if len(scores):
            min = scores[0]
            max = scores[0]
    for s in scores:
        if s < min :
            min = s
            most_least[LEAST] += 1
        if s > max : 
            max = s
            most_least[MOST] += 1
    return most_least    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()