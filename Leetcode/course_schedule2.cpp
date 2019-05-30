#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  	int n = numCourses;
  	graph = vector<vector<int>>(n);
  	v = vector<bool>(n, 0);
  	cyc = vector<bool>(n, 0);
   	for(auto p : prerequisites) {
   		graph[p[0]].push_back(p[1]);
   	}
   	for(int i=0; i<n; i++) {
   		if(!v[i] && check_cycle(i)) return {};
   	}
   	v = vector<bool>(n, 0);
   	for(int i=0; i<n; i++) {
   		if(!v[i]) topo_sort(i);
   	}
   	vector<int> res;
   	while(!st.empty()) {
   		res.push_back(st.top());
   		st.pop();
   	}
   	reverse(res.begin(), res.end());
   	return res;
  }

  void topo_sort(int u) {
  	v[u] = 1;
  	vector<int> adj = graph[u];
  	for(auto a : adj) {
  		if(!v[a]) topo_sort(a);
  	}
  	st.push(u);
  }

  bool check_cycle(int u) {
		v[u] = 1;
		cyc[u] = 1;
		vector<int> adj = graph[u];
		for(auto a : adj) {
			if(!v[a] && check_cycle(a)) return 1;
			else if(cyc[a]) return 1;
		}
  	cyc[u] = 0;
  	return 0;
  }

private:
	vector<vector<int>> graph;
	vector<bool> v, cyc;
	stack<int> st;
};

int main() {
	vector<vector<int>> arr = {{1,0},{2,0},{3,1},{3,2}};
	Solution sln;
	vector<int> res = sln.findOrder(4, arr);
	for(auto r : res) cout << r << endl;
	return 0;
}