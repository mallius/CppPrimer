#!/usr/bin/env python 

def minutes(str):
	hm = str.split(":", 1)
	return int(hm[0])*60 + int(hm[1])

print minutes('23:59')
