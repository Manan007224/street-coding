#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int bfs(map<int,vi> &graph, int st, int ttl) {
	queue<int> q;
	q.push(s);
	map<int, bool> V;
	V[s] = 1;
	int reachable = 0;
	while(!q.empty() || ttl!=0){
		ttl--;
		int cr = q.top();
		q.pop();
		for(auto x: graph[cr]) {
			if(!V[x]) {
				reachable ++;
				q.push(x);
				V[x]=1;
			}
		}
	}
	return reachable;
}

int main() {
	while(1) {
		int n; cin >> n;
		int qr = 0;
		if(n == 0) break;
		while(n--) {
			map<int, vi> graph;
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int a, b, q = 0;
		cin >> a, b;
		map<int,bool> v;
		queue<int> q;
		q.push()
		while(a!=0 && b!=0) {
			qr ++;
			int res = bfs(graph, a, b);
			cout << "Case " << qr << ": " << res << " nodes not reachable from node " << a << " with TTL = " << b << endl;  
		}
	}
	return 0;
}