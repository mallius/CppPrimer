#!usr/bin/env python 
import string 
import keyword



myInput = (raw_input('Enter some number: ')).split()
print myInput 

x = sorted(myInput)
for y in reversed(x): 
	print y
