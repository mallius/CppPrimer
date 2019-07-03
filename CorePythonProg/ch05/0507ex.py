#!/usr/bin/env python 
p = raw_input('Enter a score: ')
price = float(p)
rate = float(0.14)

total = round(price * (1+rate), 2)

print total
