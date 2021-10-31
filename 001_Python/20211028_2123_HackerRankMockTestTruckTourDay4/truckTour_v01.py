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


def get_circle_length(petrolpumps):
    dist = 0
    for pump in range(petrolpumps):
        dist += pump[1]
    return dist
    
def drive(start,petrolpumps):
    dist = 0
    tank = 0
    pump = start
    while pump < (start + len(petrolpumps):
        nextpump = petrolpumps[pump % len[petrolpumps]][1]
        tank += petrolpumps[pump % len[petrolpumps]][1]
        if tank >= nextpump:
            tank -= nextpump;
            pump +=1
            dist += nextpump
        else:
            return dist
    return dist    
    
def truckTour(petrolpumps):
    # Write your code here
    #print(petrolpumps)
    start = 0
    circonference = get_circle_length(petrolpumps)
    while start < len(petrolpumps):
        if drive(start,petrolpumps) >= circonference:
            return start
        start += 1
    return -1

'''
3
1 5
10 3
3 4

start 0
circonference = 12
while 0 < 3
    if drive(0)=0 >=12
        tank = 1, pump 0
        while 0 < 3:
            nextpump =  5
            tank 1 < nextpump 5
            --> return 0
    start =1
while 1 < 3 : 
    if drive(1)=12 >=12
        dist = 0
        tank = 0
        pump = 1
        while 1 < 4
            nextpump = 3
            tank = 10
            10 <>= 3
            tank = 7
            pump = 2
            dist = 3
        while 2 < 4
            nextpump = 4
            tank = 7+3 = 10
            10 <>= 4
            tank = 6
            pump = 3
            dist = 7
        while 3 < 4
            nextpump = 5
            tank = 6 + 1 = 7
            7 <>= 5
            tank = 2
            pump = 4
            dist = 12
        while 4 < 4
    return 12
    --> return 1
        



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
