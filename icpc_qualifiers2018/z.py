
from math import pi

a1,p1 = [int(x) for x in input('').split(' ')]
r1,p2 = [int(x) for x in input('').split(' ')]

if a1/p1 > (pi * r1 * r1)/p2:
	print("Slice of pizza")
else:
	print("Whole pizza")
