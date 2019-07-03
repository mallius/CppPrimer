#!/usr/bin/env python

class P:
	'P class' 
	def __init__(self):
		print 'created an instance of ', self.__class__.__name__ 

class C(P):
	pass


p = P()
print p.__class__
print P.__bases__
print P.__doc__

c = C()
print c.__class__ 
print C.__bases__ 
print C.__doc__
