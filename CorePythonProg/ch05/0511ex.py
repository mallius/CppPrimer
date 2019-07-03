#!/usr/bin/env python 

i  = 0
while i <= 20:
	if i % 2 == 0:
		print i
	i += 1
print 
i  = 0
while i <= 20:
	if i % 2 != 0:
		print i
	i += 1

def Mod(a, b):
	if int(a) % int(b) == 0:
		return True 
	else:
		return False


print Mod(11, 2)
print Mod(12, 2)
