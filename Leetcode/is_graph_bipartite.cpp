#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
  	int n = graph.size();
  	vector<bool> v(n);
  	vector<int> c(n);
  	c[0] = 0;
  	for(int i = 0; i < n; i++) {
  		if(!v[i]) {
  			if(bfs(graph, v, c, i) == 0) return 0;
  		}
  	}
  	return 1; 
  }

  bool bfs(vii graph, vector<bool> &v, vi &c, int src) {
  	queue<int> q;
  	q.push(src); 
  	while(!q.empty()) {
  		int k = q.front();
  		q.pop();
  		v[k] = 1;
  		for(auto u : graph[k]) {
  			if(v[u] && c[u] == c[k]) return 0;
  			else if(!v[u]) {
  				c[u] = !(c[k]);
  				q.push(u);
  			}
  		}
  	}
  	return 1;
  }
};

int main() {
	return 0;
}