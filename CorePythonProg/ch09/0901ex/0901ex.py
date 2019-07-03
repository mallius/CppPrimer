#!/usr/bin/env python 

f = open('0901ex.txt')
for eachLine in f:
	if eachLine.strip()[0] != '#':
		print eachLine,
f.close()
