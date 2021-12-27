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


def isPalindrome(s):
    '''
        length = 5 5/2 = 2.5 : 0 to 4, check 0 to 2 --> ok
        if length odd, check until (length/2)
        length = 5, 4/2 = 2 : 0 to 3, will check 0 to 1
        if length even, check until 0 to (length/2 -1)
    '''
    l = len(s)
    mx = int(l/2) if len(s) % 2 == 0 else (int(l/2) -1)
    i = 0
    while i <= mx:
        if s[i] != s[l - 1 -i]:
            return False
        i += 1
    return True

def palindromeIndex(s):
    # Write your code here

'''
Input (stdin)
3
aaab
baa
aaa
Your Output (stdout)
-1
0
-1
Expected Output
3
0
-1
'''



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()
