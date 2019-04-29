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

// class Solution {
// public:
//   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//     Graph G;
//    	for(auto f: flights) {
//    		G[f[0]].pb({f[1], f[2]});
//    	}
//    	int cost = INT_MAX;
//    	vector<bool> visited(n, 0);
//    	dfs(src, dst, K, visited, G, cost, 0);
//    	return (cost == INT_MAX ? -1 : cost);
//   }

//   void dfs(int src, int dst, int k, vector<bool> &visited, Graph &G, int &cost, int used) {
//   	if(src == dst) {
//   		cost = used;
//   		return;
//   	}
//   	if(k==0)
//   		return;
//   	visited[src] = 1;
//   	for(auto n: G[src]) {
//   		if(!visited[n.fi]) {
//   			if(used + n.se <= cost) {
//   				dfs(n.fi, dst, k-1, visited, G, cost, used + n.se);
//   			}
//   		}
//   	}
//   	visited[src] = 0;
//   }
// };

class Solution{
public:
	struct node {
		int cost, src, k;
		node(int c, int s, int k): cost(c), src(s), k(k) {}
	};

	struct compare {
		bool operator() (node &n1, node &n2) {
			return n1.cost >= n2.cost;
		}
	};

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		Graph G;
		for(auto f: flights) {
			G[f[0]].pb({f[1], f[2]});
		}
		priority_queue<node, vector<node>, compare> pq;
		pq.push(node(0, src, K));	
		while(!pq.empty()) {
			node curr = pq.top();
			pq.pop();
			cout << curr.cost << " " << curr.src << " " << curr.k << endl;
			if(curr.src == dst)
				return curr.cost;
			if(curr.k>=0) {
				for(auto x: G[curr.src]) {
					pq.push(node(curr.cost + x.se, x.fi, curr.k-1));
				}
			}
		}
	}
};

int main() {
	Solution sln;
	vii t = {{0,1,100}, {1,2,100}, {0,2,500}};
	cout << sln.findCheapestPrice(3, t, 0, 2, 1) << endl;
	return 0;
}