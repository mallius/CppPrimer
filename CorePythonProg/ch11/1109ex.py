#!/usr/bin/env python 
def aver(x, y):
	return (x+y)/ 2

ret = reduce(aver, [1,3,6])
print ret
