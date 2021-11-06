#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximumPerimeterTriangle' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY sticks as parameter.
#

def maximumPerimeterTriangle(sticks):
    # Write your code here
    triangles = []
    perimeter = []
    sticks.sort(reverse=True)
    sides = itertools.combinations(sticks,3)
    for a,b,c in sides:
        if a+b>c and a+c>b and b+c>a:
            comb = sorted([a,b,c])
            triangles.append(comb)
            perimeter.append(sum(comb))
            #print(f'triangles : {triangles}, perimeter : {perimeter}')
    if len(triangles) == 0:
        return [-1]
    elif len(triangles) == 1:
        return list(triangles[0])
    else: # len(triangles) >1 : 
        # Choose the one with the longest maximum side.
        max_perim_index = perimeter.index(max(perimeter))
        cnt = perimeter.count(perimeter[max_perim_index])
        if cnt == 1:
            return triangles[max_perim_index];
        else: #If more than one has that maximum, 
            #choose from them the one with the longest minimum side.
            i = max_perim_index + 1
            longest_min_side = triangles[max_perim_index][0]
            while i < len(triangles) and cnt > 1:
                if perimeter[i] == perimeter[max_perim_index] and triangles[max_perim_index][0] > longest_min_side : 
                    max_perim_index = i;
                    longest_min_side = triangles[max_perim_index][0]
                i += 1
                cnt -= 1
            return triangles[max_perim_index];

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    sticks = list(map(int, input().rstrip().split()))

    result = maximumPerimeterTriangle(sticks)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
