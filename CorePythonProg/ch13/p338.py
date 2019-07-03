#!/usr/bin/env python 
class MyClass(object):
	'MyClass class definition'
	myVersion = '1.1'
	def showMyVersion(self):
		print MyClass.myVersion

print dir(MyClass)
print MyClass.__dict__ 
print MyClass.__name__
print MyClass.__doc__
print MyClass.__base__
print MyClass.__class__
