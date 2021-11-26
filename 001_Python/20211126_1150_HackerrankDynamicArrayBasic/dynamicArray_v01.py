#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'dynamicArray' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def dynamicArray(n, queries):
    # Write your code here
    arr = [[] for i in range(n)]
    answers = []
    lastAnswer = 0
    QUERY_TYPE_IDX = 0
    X_IDX = 1
    Y_IDX = 2
    for s in queries:
        x = s[X_IDX]
        y = s[Y_IDX]
        idx = (x ^ lastAnswer) % n
        if s[QUERY_TYPE_IDX] == 1:
            arr[idx].append(y)
        if s[QUERY_TYPE_IDX] == 2:
            lastAnswer = arr[idx][y % len(arr[idx])]
            answers.append(lastAnswer)
    return answers
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    result = dynamicArray(n, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()