#!/usr/bin/env python 

str = raw_input('Enter a string like 03:30 >')
hm = str.split(":", 1)

print int(hm[0])*60 + int(hm[1])
