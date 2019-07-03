#!/usr/bin/env python 
def mult(x, y):
	return x*y

ret = reduce(mult, range(1,4,1))
print ret

ret = reduce((lambda x,y: x*y), range(1, 4, 1))
print ret
