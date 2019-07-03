#!/usr/env python 
def fibonacci(n):
	f = 1
	s = 1
	fibo = []
	for i in range(n):
		if i < 2:
			ret = 1
			fibo.append(ret) 
		else:
			ret = f+s 
			f = s 
			s = ret 
			fibo.append(ret) 
	return fibo


def main():
	print fibonacci(10)

if __name__ == '__main__':
	main()
