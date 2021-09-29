#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    l = len(arr)
    pos = 0.0
    neg = 0.0
    zero = 0.0
    if l:
        for nb in arr:
            if nb > 0:
                pos +=1
            elif nb < 0:
                neg +=1
            else:
                zero += 1
        #print("%.6f\n%.6f\n%.6f" % (pos/l, neg/l, zero/l))
        print(f'{pos/l:.6f}\n{neg/l:.6f}\n{zero/l:.6f}\n')
    else:
        print("%.6f\n%.6f\n%.6f" % (pos, neg, zero))
    
    
    
if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)