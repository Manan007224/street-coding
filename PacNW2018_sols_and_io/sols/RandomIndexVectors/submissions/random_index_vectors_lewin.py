from collections import defaultdict
n,k = map(int, raw_input().split())

class RIV():
	def __init__(self, read=False):
		self.mp = defaultdict(int)
		if read:
			g = map(int, raw_input().split())
			for k in g[1:]:
				self.mp[abs(k)] = 1 if k > 0 else -1

	def __str__(self):
		s = [len(self.mp)]
		for k in sorted(self.mp.keys()):
			s.append(k*self.mp[k])
		return " ".join(map(str,s))

def clamp(x):
	return max(-1,min(x,1))

def combine(a1,a2,f):
	ret = RIV()
	for k in set(a1.mp.keys()+a2.mp.keys()):
		g = clamp(f(a1.mp[k],a2.mp[k]))
		if g != 0:
			ret.mp[k] = g
	return ret

def shift(a,s):
	ret = RIV()
	for k,v in a.mp.iteritems():
		t = (k-s)%n
		if t == 0: t = n
		if v != 0:
			ret.mp[t] = v
	return ret

m1 = RIV(True)
m2 = RIV(True)

print combine(m1,m2,lambda x,y:x+y)
print combine(m1,m2,lambda x,y:x*y)
print shift(m1,k)
print shift(m2,k)
