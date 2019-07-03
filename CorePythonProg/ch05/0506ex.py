#!/usr/bin/env python 

s = raw_input('Enter a string like "1 2 +" :')
cal = s.split(" ", 2)
symbol = cal[2] 
a = float(cal[0])
b = float(cal[1])

if symbol != '+' and symbol != '-' and symbol != '*' and symbol != '-':
	print 'Wrong'
else:
	if symbol == '+':
		ret = a + b
	elif symbol == '-':
		ret = a - b
	elif symbol == '*':
		ret = a * b
	elif symbol == '/':
		ret = a / b
	print ret

