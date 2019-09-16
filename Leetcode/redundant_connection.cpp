#include <bits/stdc++.h>
using namespace std;

struct unf {
	vector<int> p;

	unf(int x) {
		p = vector<int>(x);
		for(int i=1; i<=x; i++) p[i]=i;
	}

	int find(int x) {
		if(p[x]==x) return x;
		p[x] = find(p[x]);
		return p[x];
	}

	void join(int x, int y) {
		p[find(x)] = p[find(y)];
	}
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  	unf u(1000);
    vector<int> res;
  	for(auto e:edges) {
  		if(u.find(e[0])==u.find(e[1]))
  			return {e[0],e[1]};
  		u.join(e[0],e[1]);
  	}
  }
};

int main() {
	vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,4},{1,5}};
	Solution sln;
	vector<int> res = sln.findRedundantConnection(v);
	for(auto r: res) cout << r << endl;
	return 0;
}