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
    count = 0
    if len(s) % 2 != 0:
        return -1
    half = int(len(s)/2)
    # split string into 2 lists of equal length
    s1 = list(s[0:half])
    s2 = list(s[half:])
    count_s1 = {}
    for c in s1:
        if count_s1.get(c) == None:
            count_s1[c] = 1
        else:
            count_s1[c] += 1
    for c in count_s1.keys():
        if count_s1[c] > s2.count(c):
            count += count_s1[c] - s2.count(c);

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
