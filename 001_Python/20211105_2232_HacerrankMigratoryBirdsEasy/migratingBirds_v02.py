#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'migratoryBirds' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def migratoryBirds(arr):
    # Write your code here
    cnt = 5*[0]
    s = set(arr)
    for i in range(len(s)):
        cnt[i] = arr.count(i+1)
    maxim = max(cnt)
    if cnt.count(maxim) == 1:
        return (cnt.index(maxim) +1)
    indexes = []
    for i in range(len(cnt)):
        if cnt[i] == maxim:
            indexes.append(i)
    return min(indexes) +1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
