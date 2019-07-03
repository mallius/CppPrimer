#!/usr/bin/env python 

f = open('0905ex.txt')
for eachLine in f:
	score = eachLine.strip().split('|')
	print score[0], score[1], score[2]
f.close()
