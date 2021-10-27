#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'palindromeIndex' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def is_palindrome(s):
    start = 0;
    while start <= len(s) -1 -start:
        if s[start] != s[len(s) -1 -start]:
            return start
        start +=1
    return -1
    
def palindromeIndex(s):
    # Write your code here
    if len(s) == 0:
        return -1
    start = is_palindrome(s)
    if start == -1:
        return -1
    # otherwise, test by removing char at position start
    # and removing char at position len(s) -1 -start
    #print(f'start = {start}')
    if start != 0:
        s1 = s[:start] + s[start+1:]
    else:
        s1 = s[start+1:]
    #print(f's = {s}, s1 = {s1}')
    #s1.pop(start)
    if is_palindrome(s1) == -1:
        return start
    if start != 0:
        s1 = s[:len(s)-1 -start] + s[len(s)-1 -start +1:]
    else:
        s1 = s[0:(len(s)-1 - start)]
    #print(f's = {s}, s1 = {s[0:3]}')
    #s1.pop(len(s)-1 -start)
    if is_palindrome(s1) == -1:
        return len(s) -1 -start
    return -1
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()

