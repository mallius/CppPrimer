#!/usr/bin/env python 

f1 = open('1_0906ex.txt')
f2 = open('2_0906ex.txt')

allLines1 = f1.readlines()
allLines2 = f2.readlines()

cnt = 0
step = 0
for l in allLines1:
	if l == allLines2[cnt]:
		pass
	else:
		print 'diffent line:\t', cnt+1
		for w in l:
			if w != allLines2[cnt][step]:
				print 'diffent col:\t', step+1
			step += 1

	cnt += 1

f1.close()
f2.close()
