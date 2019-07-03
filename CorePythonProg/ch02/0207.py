#!/usr/bin/env python
s = raw_input('Enter a string: ')

for i in range(len(s)):
	print s[i]

cnt = 0
while cnt < len(s):
	print s[cnt]
	cnt += 1
