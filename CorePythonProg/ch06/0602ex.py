#!usr/bin/env python 
import string 
import keyword

alphas = list(string.letters + '_')
nums = list(string.digits)
key = keyword.kwlist
kw = alphas + nums + key

print 'Welcome to the Identifier Checker v1.1' 
print 'Testees must be at least 1 chars long' 

myInput = (raw_input('Identifier to test: ')).split()
print myInput

if len(myInput) > 0: 
	if myInput[0] not in kw:
		print '''invalid: first symbol must be alphabetic'''
	else:
		for otherChar in myInput[0:]:
			if otherChar in kw:
				print '''ok as an identifier'''
			else:
				print "okay not an identifier"
