#!/usr/bin/env python

def simpleGen():
	yield 1
	yield '2 --> punch!'

myG = simpleGen()
print myG.next()
print myG.next()

for eachItem in simpleGen():
	print eachItem
