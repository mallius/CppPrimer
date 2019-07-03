#!/usr/bin/env python 

d = {'a':1, 'c':2, 'b':3, 'd':4}
s = sorted(d.items())
for x in s:
	print x[0], x[1]
