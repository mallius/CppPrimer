#!/usr/bin/evn python 

'readTextFile.py -- read and display text file'

import os
ls = os.linesep

# get filename 
while True:
	fname = raw_input('Enter filename: ') 
	if not os.path.exists(fname):
		print "Error: '%s' not exists" % fname
	else:
		break


fobj = open(fname, 'r')
for eachLine in fobj:
	print eachLine,
fobj.close()
