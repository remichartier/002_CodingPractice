#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countSort' function below.
#
# The function accepts 2D_STRING_ARRAY arr as parameter.
#

def countSort(arr):
    # Write your code here
    result = [[]]
    for i in range(len(arr)):
        if i < int(len(arr)/2):
            arr[i][1] = '-'
        if int(arr[i][0]) > len(result) -1:
            nb_to_extend = int(arr[i][0]) - (len(result) -1)
            for j in range(nb_to_extend):
                # create additional elements to store arr[i]
                result.append([])    
        # now can store/append this element at the right place.
        result[int(arr[i][0])].append(arr[i][1])
    # convert to string
    output = ""
    for a in result:
        for b in a:
            output += b + ' '
    # remove the last space at the end
    output.rstrip()
    print(output)
    
    
if __name__ == '__main__':
    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(input().rstrip().split())

    countSort(arr)
