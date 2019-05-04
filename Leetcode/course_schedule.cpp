#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
typedef unordered_map<int, unordered_set<int>> Graph;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  	int n = prerequisites.size();
  	Graph courses;
  	for(auto p: prerequisites) courses[p[1]].insert(p[0]);
  	vector<int> v(n,0), curr(n,0);
  	bool works = 1;
  	for(int i=0; i<numCourses; i++) {
  		if(!v[i] && check_cycle(v, curr, i, courses)) {
  			// cout << "cycle " << i << endl; 
  			works = 0;
  			break;
  		}
  	}
  	return works;
  }

  bool check_cycle(vi &v, vi &curr, int start, Graph &courses) {
  	if(!v[start]) {
  		v[start] = 1;
  		curr[start] = 1;
  		unordered_set<int> adj = courses[start];
  		for(auto a: adj) {
  			if(!v[a] && check_cycle(v, curr, a, courses)) return 1;
  			if(curr[a]) return 1; 
  		}
  	}
  	curr[start]=0;
  	return 0;
  }
};

int main() {
	vii a = {{0,2}, {2,1}, {1,1}};
	vii a1 = {{1,0}};
	Solution sln;
	cout << sln.canFinish(2, a1) << endl;
	return 0;
}