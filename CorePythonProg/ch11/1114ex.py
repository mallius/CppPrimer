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

def fibonacci2(n):
	if n <= 2:
		return 1
	else:
		return (fibonacci2(n-1) + fibonacci2(n-2))

def main():
	print fibonacci(10)
	print fibonacci2(10)

if __name__ == '__main__':
	main()
