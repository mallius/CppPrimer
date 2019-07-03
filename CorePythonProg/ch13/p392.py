#!/usr/bin/env python
class DevNull(object):
	def __get__(self, obj, typ=None):
		pass 
	def __set__(self, obj, val):
		pass

class DevNull2(object):
	def __get__(self, obj, typ=None):
		print 'Accessing attribute... ignoring' 
	def __set__(self, obj, val):
		print 'Attempt to assign %r... ignoring' % (val) 

class DevNull3(object):
	def __init__(self, name=None):
		self.name = name 
	def __get__(self, obj, typ=None):
		print 'Accessing [%s]... ignoring' % (self.name) 
	def __set__(self, obj, val):
		print 'Assigning %r to [%s]... ignoring' % (val, self.name)
