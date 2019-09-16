#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
  	unordered_map<string, string> rec;
  	int n = accounts.size();
  	for(int i=0; i<n; i++) {
  		for(int j=1; j<accounts[i].size(); j++) {
  			if(rec.find(accounts[i][j]) == rec.end()) rec[accounts[i][j]] = accounts[i][0];
  			graph[accounts[i][1]].push_back(accounts[i][j]);
  			graph[accounts[i][j]].push_back(accounts[i][1]);
  		}
  	}
  	vector<vector<string>> res;
  	unordered_set<string> v;
  	for(auto gg: graph) {
  		string g = gg.first;
  		if(v.find(g) == v.end()) {
  			unordered_set<string> v1;
  			dfs(v, v1, g);
  			vector<string> r(v1.begin(), v1.end());
  			sort(r.begin(), r.end());
  			r.insert(r.begin(), rec[g]);
  			res.push_back(r);
  		}
  	}
  	return res;
  }

  void dfs(unordered_set<string> &v, unordered_set<string> &v1, string u) {
  	v.insert(u);
  	v1.insert(u);
  	for(auto x : graph[u]) {
  		if(v.find(x) == v.end()) dfs(v, v1, x);
  	}
  }


private:
	unordered_map<string, vector<string>> graph;
};

int main() {
	vector<vector<string>> t = {{"m1", "b1", "b2", "b3"}, {"m2", "d1", "d2", "b2"}};
	Solution sln;
	vector<vector<string>> res = sln.accountsMerge(t);
	for(auto rr: res) {
		for(auto r: rr) cout << r << " ";
		cout << endl;
	}
	return 0;
} 