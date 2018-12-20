s, a, b = (x for x in raw_input().split())
a = int(a)
b = int(b)

def solve(dp, s, a, b, minimize):
    if len(s) == 0:
        return ("-1", 0.0)
    if (s, a, b) not in dp:
        move = "-1"
        ret = float(s) if minimize else -1.0
        could = False
        for mask in xrange(2**len(s)):
            v = 0
            moved = ""
            for i in xrange(len(s)):
                if mask & 2**i:
                    v += ord(s[i]) - ord('0')
                    moved += s[i]
            if v != a+b:
                continue
            could = True
            ns = ""
            nv = 0.0
            for i in xrange(len(s)):
                if (mask & (2**i)) == 0:
                    ns += s[i]
            for na in xrange(1, 7):
                for nb in xrange(1, 7):
                    nv += solve(dp, ns, na, nb, minimize)[1]
            nv /= 36
            if minimize and nv < ret:
                ret = nv
                move = moved
            elif not minimize and nv > ret:
                ret = nv
                move = moved
        if not could:
            move = "-1"
            ret = float(s)
        dp[(s, a, b)] = (move, ret)
    return dp[(s, a, b)]

def printAnswer(ret):
    print "%s %.5f" % (ret[0], ret[1])

printAnswer(solve({}, s, a, b, True))
printAnswer(solve({}, s, a, b, False))
