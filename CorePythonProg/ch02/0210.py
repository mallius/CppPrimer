#!/usr/bin/env python

num = raw_input('Enter a number between 1 and 100 : ')
while float(num) < 1 or float(num) > 100:
	num = raw_input('Enter a number between 1 and 100 : ')
print num
