#!/usr/env python 
def getfactors(x):
	res = []
	num = range(1, x+1, 1)
	for i in num:
		if i == 1 or x % i == 0:
			res.append(i)
	return res

def main():
	res = getfactors(12) 
	print res

if __name__ == '__main__':
	main()
