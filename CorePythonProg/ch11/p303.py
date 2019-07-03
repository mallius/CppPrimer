#!/usr/bin/env python

x = 10
def foo():
	y = 5
	bar = lambda z:x+z
	print bar(y)
	y = 8
	print bar(y)

foo()
