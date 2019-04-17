def gcd(a,b):
	return a if b==0 else gcd(b, a%b)

def crypto():
	T = int(input())
	for t in range(1, T+1):
		N, L = [int(_) for _ in input().split()]
		prods = [int(_) for _ in input().split()]
		x = 0
		while prods[x] == prods[x+1]:
			x += 1
		primes = [0]*(L+1)
		primes[x+1] = gcd(prods[x], prods[x+1])
		for i in range(x+1, len(prods)):
			primes[i+1] = prods[i] // primes[i]
		for i in range(x, -1, -1):
			primes[i] = prods[i] // primes[i+1]

		prime_set = sorted(list(set(primes)))
		mp = {}
		for i in range(0,len(prime_set)):
			mp[prime_set[i]] = chr(i+65)

		print("Case #{0}: {1}".format(t, "".join([mp[x] for x in primes])))	


if __name__ == '__main__':
	crypto()