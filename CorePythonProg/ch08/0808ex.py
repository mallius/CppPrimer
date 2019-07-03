#!/usr/env python 
def factorial(n):
	ret = 1
	for i in range(1, n+1, 1):
		ret *= i
	return ret


def main():
	print factorial(4)

if __name__ == '__main__':
	main()
