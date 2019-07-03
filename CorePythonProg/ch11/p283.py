#!/usr/bin/env python

def dictVarArgs(arg1, arg2='defaultB', **theRest):
	'display 2 regular args and keyword variable args'
	print 'formal arg 1:', arg1
	print 'formal arg 2:', arg2

	for eachXtrArg in theRest.keys():
		print 'Xtr arg %s: %s' % (eachXtrArg, str(theRest[eachXtrArg]))

dictVarArgs(1220, 740.0, c='grail')
dictVarArgs(arg2='tales', c=123, d='poe', arg1='mystery')
dictVarArgs('one', d=10, e='zoo', men = ('freud', 'gaudi'))

