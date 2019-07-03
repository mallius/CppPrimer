#!/usr/bin/env python

class myClass(object):
	def __init__(self):
		self.foo = 100

myInst = myClass()
ret = hasattr(myInst, 'foo')
print ret

ret = getattr(myInst, 'foo')
print ret

ret = hasattr(myInst, 'bar')
print ret

ret = getattr(myInst, 'bar', 'oops!')
print ret

setattr(myInst, 'bar', 'my attr')
ret = getattr(myInst, 'bar')
print ret
