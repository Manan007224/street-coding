def recur(a):
    n = a
    if a==1:
        return 1
    else:
        return 2(recur(a//2))+n

ans = recur(8)
print(ans)
