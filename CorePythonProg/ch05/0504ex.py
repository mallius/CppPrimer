#!/usr/bin/env python 
y = raw_input('Enter a score: ')
year = int(y)

if (year % 4 == 0 and year % 100 != 0) or (year % 4 == 0 and year % 100 == 0):
	print 'Yes'
else:
	print 'No'
