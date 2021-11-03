#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'noPrefix' function below.
#
# The function accepts STRING_ARRAY words as parameter.
#

def is_prefix(a, b):
    if len(a) > len(b):
        return False
    if b.find(a) == 0:
        return True
    return False
        
def noPrefix(words):
    # Write your code here
    # take each words of the list.
        # check if not a prefix of all the other words 
        # if other words are longer
    for i in range(len(words)):
        for j in range(len(words)):
            if i == j:
                continue
            if is_prefix(words[j],words[i]):
                print("BAD SET")
                print(words[i])
                return
    print("GOOD SET")
    
if __name__ == '__main__':
    n = int(input().strip())

    words = []

    for _ in range(n):
        words_item = input()
        words.append(words_item)

    noPrefix(words)
