# coding=utf-8

'''
Given 2 strings, write a method to decide if one is the permutation of the other

'''
def isStringsPermutedDic0(a,b) :
	if len(a) != len(b) or len(a) == 0 or len(b) == 0 or a == b :
		return(False)
	dictio = {}
	for c in a :
		if c in dictio :
			dictio[c] += 1
		else :
			dictio[c] = 1
	# here hash table for string a is computed.
	# Now we can decrement with chars in b string
	for c in b :
		if c in dictio :
			dictio[c] -= 1
		else :
			return(False)
	# at the end, if all values in diction are 0 --> string permuted, otherwise, not permuted.
	for c in dictio :
		if dictio[c] != 0 :
			return(False)
	# if code reached this step --> all dictio[c] where at 0 --> permuted strings --> return(True)
	return(True)

def isStringsPermutedDic1(a,b) :
	if len(a) != len(b) or len(a) == 0 or len(b) == 0 or a == b :
		return(False)
	dictio = {}
	for c in a :
		if c in dictio :
			dictio[c] += 1
		else :
			dictio[c] = 1
	# here hash table for string a is computed.
	# Build hash table for string b
	dictio_b = {}
	for c in b :
		if c in dictio_b :
			dictio_b[c] += 1
		else :
			dictio_b[c] = 1
	# here hash table for string b is computed.
	# now we can return comparison of dictionaries
	#return(cmp(dictio,dictio_b))
	# however cmp() does not exist anymore in Python 3.
	# so we need to compare manually the dictionnaries.
	return(sorted(dictio) == sorted(dictio_b))

def isStringsPermutedSort(a,b) :
	if len(a) != len(b) or len(a) == 0 or len(b) == 0 or a == b :
		return(False)
	return(sorted(a) == sorted(b))



a = "implement"
b = "tnemelpmi"
c = "slip"
d = "tneme0pmi"

print("using isStringsPermutedDic0")
print( a + " and " + a )
if isStringsPermutedDic0(a,a) : print("True")
else : print("False")
print( a + " and " + b )
if isStringsPermutedDic0(a,b) : print("True")
else : print("False")
print( a + " and " + c )
if isStringsPermutedDic0(a,c) : print("True")
else : print("False")
print( a + " and " + d )
if isStringsPermutedDic0(a,d) : print("True")
else : print("False")

print("using isStringsPermutedDic1")
print( a + " and " + a )
if isStringsPermutedDic1(a,a) : print("True")
else : print("False")
print( a + " and " + b )
if isStringsPermutedDic1(a,b) : print("True")
else : print("False")
print( a + " and " + c )
if isStringsPermutedDic1(a,c) : print("True")
else : print("False")
print( a + " and " + d )
if isStringsPermutedDic1(a,d) : print("True")
else : print("False")

print("using isStringsPermutedSort")
print( a + " and " + a )
if isStringsPermutedSort(a,a) : print("True")
else : print("False")
print( a + " and " + b )
if isStringsPermutedSort(a,b) : print("True")
else : print("False")
print( a + " and " + c )
if isStringsPermutedSort(a,c) : print("True")
else : print("False")
print( a + " and " + d )
if isStringsPermutedSort(a,d) : print("True")
else : print("False")

'''
python3 isStringPermutaiton_v01.py 

'''


