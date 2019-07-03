#!/usr/bin/env python

print map((lambda x: x+2), [0, 1, 2, 3, 4, 5])
print map(lambda x: x**2, range(6))
print [x+2 for x in range(6)]
print [x**2 for x in range(6)]
print map(lambda x, y: x+y, [1,3,5], [2,4,6])
print map(lambda x, y: (x+y, x-y), [1,3,5],[2,4,6])
print map(None, [1,3,5], [2, 4, 6])
