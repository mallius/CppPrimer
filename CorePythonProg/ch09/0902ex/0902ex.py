#!/usr/bin/env python 

f = open('0902ex.txt')
cnt = 0
line = 2
for eachLine in f:
	if cnt < line :
		print eachLine,
		cnt += 1
f.close()
