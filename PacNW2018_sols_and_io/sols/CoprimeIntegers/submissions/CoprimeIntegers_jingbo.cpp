#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 10000000;

int f[MAXN + 1], g[MAXN + 1];

inline void preprocess(int n)
{
    memset(f, -1, sizeof(f));
    g[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (f[i] == -1) {
            f[i] = i;
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    if (f[j] == -1) {
                        f[j] = i;
                    }
                }
            }
        }
        int x = i, sign = 1;
        while (x > 1) {
            int y = f[x];
            x /= y;
            if (f[x] == y) {
                sign = 0;
                break;
            }
            sign = -sign;
        }
        g[i] = sign;
    }
}

inline long long solve(long long n, long long m)
{
    long long ret = 0;
    for (int i = 1; i <= n && i <= m; ++ i) {
        if (g[i]) {
// fprintf(stderr, "%d %d\n", i, g[i]);
            ret += g[i] * (n / i) * (m / i);
        }
    }
    return ret;
}

int main()
{
    int a, b, c, d;
    assert(scanf("%d%d%d%d", &a, &b, &c, &d) == 4);
    assert(1 <= a && a <= b && b <= MAXN);
    assert(1 <= c && c <= d && d <= MAXN);
    preprocess(max(b, d));
    long long ret = solve(b, d) - solve(a - 1, d) - solve(b, c - 1) + solve(a - 1, c - 1);
    printf("%lld\n", ret);
    return 0;
}
