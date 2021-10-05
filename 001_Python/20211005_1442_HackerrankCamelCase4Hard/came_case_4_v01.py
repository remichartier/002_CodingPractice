# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys

OPERATION = 0
TYPE = 1
NAME = 2
SPLIT = 'S'
COMBINE = 'C'
METHOD = 'M'
CLASS = 'C'
VARIABLE = 'V'

output = []
for line in sys.stdin:
    output.clear()
    s = line.rstrip().split(';')
    #print(f's = {s}')
    if s[OPERATION] == SPLIT:
        #print(f'Operation = Split of name {s[NAME]}')
        if s[TYPE] == METHOD:
            # remove ()
            s[NAME] = s[NAME][: len(s[NAME]) - 2]
        # insert Spaces before each Uppercases and lower uppercases
        for c in s[NAME]:
            if c.isupper():
                output.append(' ')
                output.append(c.lower())
            else:
             output.append(c)
            #print(f'loop for : print output : {output}')
    if s[OPERATION] == COMBINE:
        # cases Method, Class, Variables
        #1st letter if Class --> upperCase
        # 1st letter after a space --> remove space, uppercase next letter
        # If method, add () at the end
        next_cap = False
        for i in range(len(s[NAME])):
            if i == 0 and s[TYPE] == CLASS:
                output.append(s[NAME][0].upper())  
            elif s[NAME][i] == ' ' and i < len(s[NAME]) -1:
                next_cap = True
            else:
                if next_cap == True:
                    output.append(s[NAME][i].upper())
                    next_cap = False
                    pass
                else:
                    output.append(s[NAME][i])
        if s[TYPE] == METHOD:
            output.append('(')
            output.append(')')

    print(''.join(output).lstrip(), file = sys.stdout)
