#!/usr/bin/env python 
def safe_float(obj):
	try:
		retval = float(obj)
	except:
		retval = 'could not convert non-number to float'
	except:
		retval = 'object type cannot be converted to float'
	return retval

safe_float('xyz')
#safe_float(())
