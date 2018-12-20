import heapq

n,c = map(int, raw_input().split())
ts = map(int, raw_input().split())

pq = [(0, i) for i in xrange(n)]
for ci in xrange(c):
	ct, cc = heapq.heappop(pq)
	print cc+1,
	heapq.heappush(pq, (ct+ts[ci], cc))
print
