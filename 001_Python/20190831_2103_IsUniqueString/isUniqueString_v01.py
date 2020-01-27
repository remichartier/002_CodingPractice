# coding=utf-8

'''
Algo to implement if a string has all unique characters. What if you can not use additional data structures ?

'''
def isUnique(s) :
	if len(s) == 0 :
		return(False)
	if len(s) == 1 : 
		return(True)	
	s1 = ""
	for c in s :
		if c in s1 :
			return(False)
		else :
			s1 = s1 + c
	return(True)


a = "implement"
b = "sleep"
c = "slip"

if isUnique(a) :
	print(a + " : True")
else : 
	print(a + " : False")

if isUnique(b) :
	print(b + " : True")
else : 
	print(b + " : False")

if isUnique(c) :
	print(c + " : True")
else : 
	print(c + " : False")
'''
python3 isUniqueString_v01.py 

'''


