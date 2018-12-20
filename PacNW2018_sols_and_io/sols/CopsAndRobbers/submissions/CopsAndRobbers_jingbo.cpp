#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;

const int MAXN = 128;
const int MAXC = 26;
const int MAXCOST = 100000;
const int INF = 1000000000;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int MAXNODE = MAXN * MAXN * 2 + 1;
const int MAXEDGE = MAXN * MAXN * 5 * 2;

int head[MAXNODE], vtx[MAXEDGE], nextEdge[MAXEDGE], capacity[MAXEDGE], totalEdge;
int source, sink, sign;
long long flow;
int dist[MAXNODE], pre[MAXNODE];

void addEdge(int a, int b, int c)
{
    vtx[totalEdge] = b;
    capacity[totalEdge] = c;
    nextEdge[totalEdge] = head[a];
    head[a] = totalEdge;
    ++ totalEdge;

    vtx[totalEdge] = a;
    capacity[totalEdge] = 0;
    nextEdge[totalEdge] = head[b];
    head[b] = totalEdge;
    ++ totalEdge;
}

bool bfs()
{
    for (int i = 0; i <= sink; ++ i) {
        dist[i] = INF;
    }
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();    
        for (int p = head[u]; p != -1; p = nextEdge[p]) {
            int v = vtx[p];
            if (capacity[p] > 0 && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                if (v == sink) {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}

void dinic(int u)
{
    if (u == sink) {
        int delta = INF;
        for (int v = sink, p; v != source; v = vtx[p]) {
            p = pre[v];
            delta = min(delta, capacity[p]);
            p ^= 1;
        }
        for (int v = sink, p; v != source; v = vtx[p]) {
            p = pre[v];
            capacity[p] -= delta;
            if (capacity[p] == 0) {
                sign = vtx[p ^ 1];
            }
            p ^= 1;
            capacity[p] += delta;
        }
        flow += delta;
        return;
    }
    for (int p = head[u]; p != -1; p = nextEdge[p]) {
        int v = vtx[p];
        if (capacity[p] > 0 && dist[u] + 1 == dist[v]) {
            pre[v] = p;
            dinic(v);
            if (dist[sign] < dist[u]) {
                return;
            }
            sign = sink;
        }
    }
    dist[u] = INF;
}

int n, m, c;
char mat[MAXN][MAXN + 1];
int cost[MAXC];

int main()
{
    assert(scanf("%d%d%d", &m, &n, &c) == 3);
    assert(1 <= n && n <= MAXN);
    assert(1 <= m && m <= MAXN);
    assert(1 <= c && c <= MAXC);

    for (int i = 0; i < n; ++ i) {
        assert(scanf("%s", mat[i]) == 1);
        assert(strlen(mat[i]) == m);
    }
    for (int i = 0; i < c; ++ i) {
        assert(scanf("%d", &cost[i]) == 1);
        assert(1 <= cost[i] && cost[i] <= MAXCOST);
    }

    memset(head, -1, sizeof(head));
    totalEdge = 0;
    source = -1, sink = n * m * 2;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (mat[i][j] == 'B') {
                assert(source == -1);
                source = i * m + j + n * m;
            } else if (mat[i][j] == '.') {
                addEdge(i * m + j, i * m + j + n * m, INF);
            } else {
                assert('a' <= mat[i][j] <= 'a' + c);
                addEdge(i * m + j, i * m + j + n * m, cost[mat[i][j] - 'a']);
            }

            for (int k = 0; k < 4; ++ k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && y >= 0 && x < n && y < m) {
                    addEdge(i * m + j + n * m, x * m + y, INF);
                } else {
                    addEdge(i * m + j + n * m, sink, INF);
                }
            }
        }
    }
    assert(source != -1);

    flow = 0;
    while (bfs() && flow < INF) {
        dinic(source);
    }
    if (flow < INF) {
        printf("%lld\n", flow);
    } else {
        puts("-1");
    }

    return 0;
}
