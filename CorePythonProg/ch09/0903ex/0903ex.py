#!/usr/bin/env python 

f = open('0903ex.txt')
n = len([line for line in f])
f.close()
print n
