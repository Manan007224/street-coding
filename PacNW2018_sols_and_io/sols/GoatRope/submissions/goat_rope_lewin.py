import math
x,y,x1,y1,x2,y2 = map(int, raw_input().split())
print "%.3f"%(math.hypot(max(x1-x,x-x2,0), max(y1-y,y-y2,0)))
