#!/usr/bin/env python 
def odd(year):
	if (year % 4 == 0 and year % 100 != 0) or (year % 4 == 0 and year % 100 == 0):
		return True
	else:
		return False

print filter(odd, [1996,1998,1999,2000])
