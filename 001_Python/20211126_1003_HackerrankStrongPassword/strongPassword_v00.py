#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumNumber' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING password
#

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    missing_char = 0
    numbers = list("0123456789")
    lower_case = list("abcdefghijklmnopqrstuvwxyz")
    upper_case = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    special_characters = list("!@#$%^&*()-+")
    status = [0]*4
    NUMBER = 0
    UPPER = 1
    LOWER = 2
    SPECIAL = 3
    MIN_LENGTH = 6
    i = 0
    while sum(status) < len(status) and i < len(password):
        if password[i] in numbers:
            status[NUMBER] = 1
        if password[i] in lower_case:
                status[LOWER] = 1
        if password[i] in upper_case:
                status[UPPER] = 1
        if password[i] in special_characters:
                status[SPECIAL] = 1
        i += 1
    if sum(status) < len(status):
        missing_char = len(status) - sum(status)
    if len(password) + missing_char < MIN_LENGTH:
        missing_char += MIN_LENGTH - (len(password) + missing_char)
    return missing_char


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
