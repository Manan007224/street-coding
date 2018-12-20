import math
a1,p1 = map(int, raw_input().split())
r2,p2 = map(int, raw_input().split())
print ["Whole pizza", "Slice of pizza"][a1 * p2 > math.pi * r2 * r2 * p1]