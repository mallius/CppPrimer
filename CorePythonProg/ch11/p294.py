#!/usr/bin/env python

from operator import add, mul
from functools import partial 

add1 = partial(add, 1)
mul100 = partial(mul, 100)

print add1(10)
print mul100(10)
print mul100(500)
