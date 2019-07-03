#!/usr/bin/env python 
def tax(price, rate=0.14):
	return round(price * (1+rate), 2)

print tax(1, 1.0)
