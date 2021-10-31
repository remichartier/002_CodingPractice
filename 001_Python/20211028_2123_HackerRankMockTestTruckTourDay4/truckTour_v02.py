#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'truckTour' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
#

'''
N petrol pumps
each pump : amount, dist next pump
Calculate the first point from where the truck will be able to complete the circle.
1 km for each liter.
output : integer smallest index of petrol pump from which we can start the tour
'''
    
def truckTour(petrolpumps):
    # Write your code here

    nb_pumps = len(petrolpumps)
    for start in range(nb_pumps):
        max_pump = start + nb_pumps
        tank = 0
        i = start
        while i < max_pump:
            tank += petrolpumps[i % nb_pumps][0]
            next_pump = petrolpumps[i % nb_pumps][1]
            if tank >= next_pump:
                tank -= next_pump
            else:
                break
            i +=1
        if i == max_pump:
            return start
    return -1

    
'''
3
1 5
10 3
3 4

nb_pumps = 3
for start in range(3)
    start = 0
    max_pump = 3
    tank = 0
    i = 0
    while 0 > 3
    tank = 1
    next_pump = 5
    if 1 >= 5 --> not --> break
    if 1 == 3 --> not

for start in range(3)
    start = 1
    max_pump = 4
    tank = 0
    i = 1
    while 1 < 4
        tank = 10
        next_pump = 3
        if 10 >= 3
            tank = 7
        i = 2
        if 2 == 4 --> not
    while 2 < 4 
        tank = 10
        next_pump = 4
        if 10 >= 4
        tank = 6
        i = 3
        if 3 == 4 --> not
    while 3 < 4 
        tank = 7
        next_pump = 5
        if 7 >= 5
            tank = 2
        i = 4
        if 4 == 4 --> return 1
'''



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    petrolpumps = []

    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)

    fptr.write(str(result) + '\n')

    fptr.close()
