from collections import Counter
mod = 998244353
n,k = map(int, raw_input().split())
c = Counter(map(int, raw_input().split()))
if len(c)<k:
	print 0
else:
	poly = [1]
	for v in c.values():
		npoly = poly[:]
		npoly.append(0)
		for i in xrange(len(poly)):
			npoly[i+1] = (npoly[i+1] + v * poly[i]) % mod
		poly = npoly[:k+1]
	print poly[k]
