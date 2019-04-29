#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second
typedef unordered_map<int, vector<pii>> Graph;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    Graph G;
   	for(auto f: flights) {
   		G[f[0]].pb({f[1], f[2]});
   	}
   	int cost = INT_MAX;
   	vector<bool> visited(n, 0);
   	dfs(src, dst, K, visited, G, cost, 0);
   	return (cost == INT_MAX ? -1 : cost);
  }

  void dfs(int src, int dst, int k, vector<bool> &visited, Graph &G, int &cost, int used) {
  	if(src == dst) {
  		cost = used;
  		return;
  	}
  	if(k==0)
  		return;
  	visited[src] = 1;
  	for(auto n: G[src]) {
  		if(!visited[n.fi]) {
  			if(used + n.se <= cost) {
  				dfs(n.fi, dst, k-1, visited, G, cost, used + n.se);
  			}
  		}
  	}
  	visited[src] = 0;
  }
};

int main() {
	return 0;
}