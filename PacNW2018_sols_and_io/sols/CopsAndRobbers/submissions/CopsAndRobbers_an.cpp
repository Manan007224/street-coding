#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int> > g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  string grid, line;
  for (int i = 0; i < M; i++) {
    cin >> line;
    grid += line;
  }
  vector<LL> cost;
  LL curCost;
  for (int i = 0; i < C; i++) {
    cin >> curCost;
    cost.push_back(curCost);
  }
  int source = grid.find("B");
  Dinic dinic(2 * N * M);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      int cur = i * N + j;
      if (cur != source) {
        LL weight = 1e16;
        if (grid[cur] != '.') weight = cost[grid[cur] - 'a'];
        dinic.AddEdge(2 * cur, 2 * cur + 1, weight);
      }
      for (int d = 0; d < 4; d++) {
        int di = i + dx[d];
        int dj = j + dy[d];
        int dest = di * N + dj;
        if (dest == source) continue;
        if (di == -1 || di == M || dj == -1 || dj == N) dest = source;
        dinic.AddEdge(2 * cur + 1, 2 * dest, 1e16);
      }
    }
  }
  LL ans = dinic.MaxFlow(2 * source + 1, 2 * source);
  if (ans > 1e15) ans = -1;
  cout << ans << endl;
}
