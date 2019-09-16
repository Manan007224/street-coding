#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct compare {
  bool operator() (pii& a, pii& b) {
    return a.second > b.second;
  }
};

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
  	vector<vector<pii>> g(N+1);
  	vector<int> f(N+1, 0), d(N+1, INT_MAX);
  	priority_queue<pii, vector<pii>, compare> pq;
    int mx = INT_MIN;
  	for(auto t: times) g[t[0]].push_back({t[1], t[2]});
  	pq.push({K, 0});
  	d[K] = 0;
  	while(!pq.empty()) {
  		int u = pq.top().first;
      mx = max(mx, d[u]);
  		pq.pop();
      f[u] = 1;
  		for(auto x: g[u]) {
  			if(!f[x.first] && d[x.first] > d[u] + x.second) {
  				d[x.first] = d[u] + x.second;
  				pq.push({x.first, d[x.first]});
  			}
  		}
  	}
  	for(int i=1; i<=N; i++) if(d[i] == INT_MAX) return -1;
  	return mx;
  }
};