#!/usr/bin/env python

class Parent(object):
	def parentMethod(self):
		print 'calling parent method'

class Chid(Parent):
	def childMethod(self):
		print 'calling child method'

p = Parent()
p.parentMethod()

c = Chid()
c.childMethod()
c.parentMethod()
