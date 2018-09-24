def permut(test, start, end, lt, num):
    if start==end:
        digits = test
        total=num
        left=num
        for k in range(0,len(digits)-1):
        	left=max(left-digits[k],digits[k])
        	total=total+left
        lt.append(total)
        return
    for k in range(start, end+1):
        test[start], test[k] = test[k], test[start]
        permut(test, start+1, end, lt, num)

while True:
	length = int(input())
	if length==0:
		break
	num_cuts = int(input())
	ls = [int(x) for x in input().split(' ')]
	output=[]
	permut(ls, 0, len(ls)-1, output, length)
	print(output)