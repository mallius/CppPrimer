#!usr/bin/env python 

myInput = raw_input('Enter some number: ').split()
print myInput 

num =  [int(x) for x in myInput]

num = sorted(num)
print num 

for x in reversed(num):
	print x
