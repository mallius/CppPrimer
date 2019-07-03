#!/usr/bin/env python
class MyDataWithmethod(object):
	def printFoo(self):
		print 'You invoked printFoo()!'

class AddrBookEntry(object):
	'address book entry class'
	def __init__(self, nm, ph):
		self.name = nm 
		self.phone = ph 
		print 'Created instance for: ', self.name 
	
	def unpdatePhone(self, newph):
		self.phone = newph 
		print 'Updated phone# for:', self.name 

class EmplAddrBookEntry(AddrBookEntry):
	'Employee Address Book Entry class'
	def __init__(self, nm, ph, id, em):
		AddrBookEntry.__init__(self, nm, ph)
		self.empid = id 
		self.email = em 
	
	def updateEmail(self, newem):
		self.email = newem 
		print 'Update e-mail address for: ', self.name


john = AddrBookEntry('John Doe', '408-555-1212')
print john.name, john.phone
john.unpdatePhone('555')
print john.name, john.phone

john = EmplAddrBookEntry('John Doe', '408-555-1212', 42, 'john@span.doe')
print john.name, john.phone, john.email
john.unpdatePhone('111')
john.updateEmail('@span')
print john.name, john.phone, john.email
