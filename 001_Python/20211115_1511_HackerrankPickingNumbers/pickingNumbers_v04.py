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
    nb_value = {}
    values=[]
    # scroll array a and store values and number of values.
    for i in a:
        if nb_value.get(i) == None:
            nb_value[i] = 1
            values.append(i)
        else:
            nb_value[i] += 1
    # sort values[]
    values.sort()
    #print(f'values = {values}')
    #print(f'nb_value = {nb_value}')
    # scroll consecutive values items, if 2 colaterals, add their numbers
    # memorize longuest length 
    if len(values) == 1:
        return nb_value[values[0]]
    # then record max length of consecutive members if dist = 1
    for i in range(len(values)-1):
        longest = max(longest, nb_value[values[i]])
        if abs(values[i] - values[i+1]) <= 1:
            longest = max(longest, nb_value[values[i]] + nb_value[values[i+1]])
    longest = max(longest, nb_value[len(values) -1])
    return longest

    # but 3/10 case fails


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
