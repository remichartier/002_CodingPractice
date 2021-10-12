#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pangrams' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def pangrams(s):
    # Write your code here
    letters = set()
    #print(f'len(s) = {len(s)}')
    if len(s) < 26:
        return "not pangram"
    for c in s.lower():
        if c != " ":
            letters.add(c)
    #print(f'len(letters) = {len(letters)}')
    if len(letters) == 26:
        return "pangram"
    return "not pangram"

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
