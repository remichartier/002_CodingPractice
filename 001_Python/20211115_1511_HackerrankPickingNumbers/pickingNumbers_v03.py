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
    curr_l = 0
    n = []
    a.sort()
    print(a)
    if len(a)<2:
        return len(a)
    for i in range(0,len(a)):
        if curr_l == 0:
            n.append(a[i])
            curr_l += 1
            print(f'a[i] = {a[i]}, curr_l = {curr_l}, n = {n}')
            continue
        if len(n) == 1 and abs(a[i] - n[0]) <= 1:
            if a[i] != n[0]:
                n.append(a[i])
            curr_l += 1
            print(f'a[i] = {a[i]}, curr_l = {curr_l}, n = {n}')
            continue
        if len(n) == 1 and abs(a[i] - n[0]) > 1:
            longest = max(curr_l, longest)
            n = [a[i]]
            curr_l = 1
            print(f'a[i] = {a[i]}, curr_l = {curr_l}, n = {n}, longest = {longest}')
            continue
        if (len(n) == 2) and (a[i] in n):
            curr_l += 1
            print(f'a[i] = {a[i]}, curr_l = {curr_l}, n = {n}')
        else:
            print('failed : (len(n) == 2) and (a[i] in n)')    
            longest = max(curr_l, longest)
            curr_l = 1
            n = [a[i]]
            print(f'a[i] = {a[i]}, curr_l = {curr_l}, n = {n}, longest = {longest}')
    return longest

    # but 1/10 case fails


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
