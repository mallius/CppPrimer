#!/usr/env python 
def getfactors(x):
	res = []
	num = range(1, x+1, 1)
	for i in num:
		if i == 1 or x % i == 0:
			res.append(i)
	return res

def isprime(x):
	if len(getfactors(x)) == 2:
		return 1
	else:
		return 0

def main():
	res = getfactors(12) 
	print res
	print isprime(12)

if __name__ == '__main__':
	main()
