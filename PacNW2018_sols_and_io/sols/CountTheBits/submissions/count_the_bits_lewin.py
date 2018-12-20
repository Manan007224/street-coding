k,b = map(int, raw_input().split())

mod = 1000000009
nxt = [[((i<<1)+j)%k for j in xrange(2)] for i in xrange(k)]
dp = [[-1 for __ in xrange(k)] for ____ in xrange(b+1)]

def count(left, cmod):
	if dp[left][cmod] != -1:
		return dp[left][cmod]
	if left == 1:
		cnt, tot = 0, 0
		if nxt[cmod][0] == 0:
			cnt += 1
		if nxt[cmod][1] == 0:
			cnt += 1
			tot += 1
		dp[left][cmod] = cnt,tot
		return dp[left][cmod]

	cnt, tot = 0, 0
	x,y = count(left-1, nxt[cmod][0])
	cnt += x
	tot += y
	x,y = count(left-1, nxt[cmod][1])
	cnt += x
	tot += x+y
	cnt %= mod
	tot %= mod
	dp[left][cmod] = cnt,tot
	return cnt,tot

print count(b,0)[1]