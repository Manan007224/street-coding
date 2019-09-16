#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  	g = graph;
  	v = vector<int>(graph.size(), -1);
  	vector<int> res;
  	for(int i=0; i<graph.size(); i++) {
  		if(!is_cycle(i)) res.push_back(i);
  	}
  	return res;
  }
	
	bool is_cycle(int i) {
		if(v[i] != -1) return !v[i];
		v[i] = 0;
		for(auto u: g[i]) {
			if(v[i]) continue;
			if(!v[u]|| is_cycle(u)) return 1; 
		}
		v[i] = 1;
		return 0;
	}	

private:
	vector<vector<int>> g;
	vector<int> v;
};

int main() {
	vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
	Solution sln;
	vector<int> res = sln.eventualSafeNodes(graph);
	for(auto r: res) cout << r << "  ";
	cout << endl;
	return 0;
}