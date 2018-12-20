n = int(raw_input())
l,r = [],[]
for i in xrange(n):
	li,ri = map(int, raw_input().split())
	l.append(li)
	r.append(ri)

for j in xrange(n,-1,-1):
	c = sum(a<=j<=b for a,b in zip(l,r))
	if c == j:
		print j
		break
else:
	print -1