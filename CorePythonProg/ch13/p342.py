#!/usr/bin/env python
class P(object):
	def __del__(self):
		pass


class C(P):
	def __init__(self):
		print 'initialized'
	def __del__(self):
		P.__del__(self)
		print 'deleted'

c1 = C()
c2 = c1 
c3 = c1 
print id(c1), id(c2), id(c3)
del c1 
del c2 
del c3
