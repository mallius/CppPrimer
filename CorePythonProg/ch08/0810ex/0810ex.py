#!/usr/env python 
alpha = ['a', 'e', 'i', 'o', 'u']
num_alpha = 0

f = open('0810ex.txt') 
for eachLine in f:
	for w in eachLine:
		if w in alpha:
			num_alpha += 1
print 'the number of aeiou: %d' % num_alpha

f = open('0810ex.txt') 
word_num = len([word for line in f for word in line.split()])
print 'the number of words: %d' % word_num 

