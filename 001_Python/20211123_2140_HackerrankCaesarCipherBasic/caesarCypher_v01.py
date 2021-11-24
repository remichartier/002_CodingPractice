#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    lowercase_min = ord('a')
    uppercase_min = ord('A')
    ciphered = ""
    for char in s:
        c = ord(char)
        if c >= lowercase_min and c < lowercase_min + 26:
            ciphered += chr((((c - lowercase_min)  + k) % 26) + lowercase_min)
        elif c >= uppercase_min and c < uppercase_min + 26:
            ciphered += chr((((c - uppercase_min)  + k) % 26) + uppercase_min)
        else:
            ciphered += char
    return ciphered
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
