#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'separateNumbers' function below.
#
# The function accepts STRING s as parameter.
#

'''
def separateNumbers(s):
    # Write your code here
    print(s)
    ret = "NO"
    for length in range(int(len(s)/2)):
        # iterate on numbers of length "length"
        i = 0
        while i < len(s):
            a = int(s[i:i+length])
            next_number_length = length(str(a+1))
            # next number start at index (i + length)
            # if length of next number is next_number_length,
            # should stop at index ? i + length + next_number_length
            b = int(s[i+length:i+length+next_number_length])
            if b-a != 1:
                return "NO"
'''

# Try recursive implementation ....

def is_beautiful_number_starting_with(x, st):
    if len(st) == 0:
        return True
    length = len(str(x))
    if length > len(st):
        return False
    if x != int(st[:length]):
        return False
    if length == len(st):
        # no more digits after --> return True
        return True
    return is_beautiful_number_starting_with(x+1,st[length:])


def separateNumbers(s):
    # Write your code here
    #print('string to test : ' + s)
    for length in range(1,math.ceil(len(s)/2)):
        # iterate on numbers of length "length"
        first_number = int(s[0:length])
        #print(f'Length tested : {length}, first_number = {first_number}')
        #print(f'call is_beautiful_number_starting_with({first_number+1}, {s[length:]})')
        ret = is_beautiful_number_starting_with(first_number+1, s[length:])
        #print(f'call is_beautiful_number_starting_with({first_number+1}, {s[length:]}) returns {ret}')
        if ret == True:
            print("YES " + str(first_number))
            return
    print("NO")

# But only passes 7 Test Cases out of 22 ....





if __name__ == '__main__':
    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)
