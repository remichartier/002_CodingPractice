!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    """
    Sample Input 07:05:45PM
    Sample Output 19:05:45
    """
    output = s[0:8]
    hour = s.split(':')[0]
    if 'PM' in s and hour != '12':
        hour = str(int(hour) + 12)
    if 'AM' in s and hour == '12': 
        hour = '00'
    output = hour + s[2:8]
    # print(f'output = {output}')
    return output
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()