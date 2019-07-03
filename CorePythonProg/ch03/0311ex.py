#!/usr/bin/evn python 

'readTextFile.py -- read and display text file'

# get filename 
fname = raw_input('Enter filename: ') 
#print 

try:
	fobj = open(fname, 'r')
except IOError, e: 
	print "*** file open error: ", e
else:
	for eachLine in fobj:
		print eachLine.strip(),
	fobj.close()
