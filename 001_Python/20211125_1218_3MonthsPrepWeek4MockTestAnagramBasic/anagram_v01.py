#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'anagram' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def anagram(s):
    # Write your code here
    if len(s) % 2 != 0:
        return -1
    half = int(len(s)/2)
    # split string into 2 lists of equal length
    l1 = list(s[0:half])
    l2 = list(s[half:])
    l1.sort()
    l2.sort()
    count = 0
    for i in range(len(l1)):
        if l1[i] != l2[i]:
            count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
