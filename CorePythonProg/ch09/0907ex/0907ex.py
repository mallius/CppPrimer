#!/usr/bin/env python 

f = open('0907ex.txt')
for line in f: 
	name = line.strip().split()
	print name[0], name[1]

f.close()
