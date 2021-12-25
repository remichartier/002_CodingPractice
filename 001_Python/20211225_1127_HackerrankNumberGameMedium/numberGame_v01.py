#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'counterGame' function below.
#
# The function is expected to return a STRING.
# The function accepts LONG_INTEGER n as parameter.
#

def isPowerOf2(n):
    log_nb = math.log2(n)
    return True if log_nb == int(log_nb) else False

def getLowerPowerOf2(n):
    '''
        Function to optimize ...
        
    '''
    '''
    i = 1
    while isPowerOf2(n -i) == False and (n - i) > 1:
        i += 1
    return n - i
    '''
    
    
        
def counterGame(n):
    # Write your code here
    # Louise Always starts
    louise = 0
    richard = 1
    player = richard
    
    # power of 2 --> n = 2 power x
    # log n = x log 2
    # x = log n / log 2 --> should be an integer.
    # --> test if number power of 2 is test if (log n / log 2) is integer
    
    while n != 1:
        player = (player + 1) % 2
        print(f'Player = {player}, n = {n}')
        print(f'isPowerOf2(n) = {isPowerOf2(n)}')
        if isPowerOf2(n):
            n = n / 2
        else:
            # reduce it by next lower number which is a power of 2
            # it give a power of 2, and n = n - lowerPowerOf2
            # lowerPowerOf2 % 2 = 0
            lowerPowerOf2 = getLowerPowerOf2(n)
            print(f'getLowerPowerOf2({n}) = {getLowerPowerOf2(n)}')
            n = n - lowerPowerOf2
            # Then pass it to next player
    
    # n now is 1 ==> return current player
    return 'Richard' if player == richard else 'Louise'
    
'''
Exemple : 6
Louise 6 is power 2 ? False ==> pass 6 - 4 = 2 to Richard.
Richard 2 is power 2 --> /2 = 1 --> Reaches 1 --> Richard wins
'''
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'counterGame' function below.
#
# The function is expected to return a STRING.
# The function accepts LONG_INTEGER n as parameter.
#

def isPowerOf2(n):
    log_nb = math.log2(n)
    return True if log_nb == int(log_nb) else False

def getLowerPowerOf2(n):
    '''
        Function to optimize ...
        
    '''
    
    i = 1
    while isPowerOf2(n -i) == False and (n - i) > 1:
        i += 1
    return n - i
    
    # But some timeouts happen due to brute force of this function
    
    
        
def counterGame(n):
    # Write your code here
    # Louise Always starts
    louise = 0
    richard = 1
    player = richard
    
    # power of 2 --> n = 2 power x
    # log n = x log 2
    # x = log n / log 2 --> should be an integer.
    # --> test if number power of 2 is test if (log n / log 2) is integer
    
    while n != 1:
        player = (player + 1) % 2
        print(f'Player = {player}, n = {n}')
        print(f'isPowerOf2(n) = {isPowerOf2(n)}')
        if isPowerOf2(n):
            n = n / 2
        else:
            # reduce it by next lower number which is a power of 2
            # it give a power of 2, and n = n - lowerPowerOf2
            # lowerPowerOf2 % 2 = 0
            lowerPowerOf2 = getLowerPowerOf2(n)
            print(f'getLowerPowerOf2({n}) = {getLowerPowerOf2(n)}')
            n = n - lowerPowerOf2
            # Then pass it to next player
    
    # n now is 1 ==> return current player
    return 'Richard' if player == richard else 'Louise'
    
'''
Exemple : 6
Louise 6 is power 2 ? False ==> pass 6 - 4 = 2 to Richard.
Richard 2 is power 2 --> /2 = 1 --> Reaches 1 --> Richard wins
'''
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
