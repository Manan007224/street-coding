n,k=map(int,input().split(" "))

a=list(map(int, input().split(" ")))
b=list(map(int, input().split(" ")))

def sign(a):
	if a>0:return 1
	else: return -1

def summ(a,b):
	v=[]
	tbl={}
	for ia in a[1:]:
		tbl[abs(ia)]=sign(ia)
	#print(tbl)
	for ib in b[1:]:
		if abs(ib) in tbl:
			r=tbl[abs(ib)] + sign(ib)
			del tbl[abs(ib)]
			if r == 0:
				continue
			else:
				v.append(sign(r) * abs(ib))
		else:
			v.append(ib)
	for k,vv in tbl.items():
		v.append(k*vv)
	rrr=sorted(v, key=lambda x:abs(x))
	return [len(rrr)]+rrr

def rotate(arr,k,n):
	rr=[]
	for i in range(1,len(arr)):
		r=0
		absi=abs(arr[i])
		if absi <= k:
			r=n-(k-absi)
		else:
			r=(absi-k)%n
		
		rr.append(sign(arr[i])*r)
	
	rrr=sorted(rr, key=lambda x:abs(x))
	return [len(rrr)]+rrr

def mul(a,b):
	v=[]
	tbl={}
	for ia in a[1:]:
		tbl[abs(ia)]=sign(ia)
	
	for ib in b[1:]:
		if abs(ib) in tbl:
			r=ib*tbl[abs(ib)]
			v.append(r)
	rr=sorted(v, key=lambda x: abs(x))
	return [len(rr)]+rr

s=summ(a,b)
m=mul(a,b)
r1=rotate(a,k,n)
r2=rotate(b,k,n)

def aprint(a):
	print(" ".join(map(str,a)))

aprint(s)
aprint(m)
aprint(r1)
aprint(r2)

"""
30 13
6 6 -9 -13 18 22 26
8 -1 3 7 11 13 19 20 -27
"""
