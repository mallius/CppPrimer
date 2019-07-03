#!/usr/bin/env python 

import types

num = 1
f = 1.0
if type(num) == type(0):
	print 'Yes'
if type(num) is types.IntType:
	print 'Yes IntType'
if type(f) is types.FloatType:
	print 'Yes FloatType'
