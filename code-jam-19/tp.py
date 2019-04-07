def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

def slv():
    [n, l] = list(map(int, input().split()))
    a = list(map(int, input().split()))
    v = [0] * (l+1)
    ref = -1
    for i in range(l-1):
        if a[i] != a[i+1]:
            v[i+1] = gcd(a[i], a[i+1])
            print("og", v[i+1], a[i], a[i+1])
            ref = i+1
            break
    for i in range(ref-1, -1, -1):
        # print("fs", i)
        print("fs ", a[i], v[i+1], a[i] // v[i+1])
        v[i] = a[i] // v[i+1]
        # print(v[i])
    for i in range(ref+1, l+1):
        # print("ss", i)
        print("ss ", a[i-1], v[i-1], a[i-1] // v[i-1])
        v[i] = a[i-1] // v[i-1]
        # print(v[i])
    p = []
    for x in v:
        if x not in p:
            p.append(x)
    p = sorted(p)
    res = ''.join([chr(ord('A')+p.index(x)) for x in v])
    return res

t = int(input())
for i in range(t):
    print ("Case #%d: %s" % (i+1, slv()))