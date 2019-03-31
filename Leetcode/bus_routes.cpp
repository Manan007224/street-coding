#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef unordered_map<int,vi> mp;


class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
  	unordered_map<int,vi> rc;
  	vii graph(routes.size());
  	unordered_set<int> src, dest;
  	queue<pair<int,int>> q;
  	for(int i=0; i<routes.size(); i++) {
  		for(int j=0; j<routes[i].size(); j++) {
  			if(rc.find(routes[i][j])==rc.end()) rc.insert(routes[i][j],i);
  			else rc[routes[i][j]].push_back(i);
  			vi nei = rc[routes[i][j]];
  			for(auto n: nei) graph[i].push_back(n);
  		}
  	}
  	vi ss = rc[S], tt = rc[T];
  	for(int i=0; i<ss.size(); i++) src.insert(ss[i]), q.push({ss[i],0});
  	for(int i=0; i<tt.size(); i++) dest.insert(tt[i]);
  	while(q.empty()) {
  		auto x = q.top();
  		q.pop();
  		int node = x.first, dist = x.second;
  		if(dest.find(node)!=dest.end()) return dist+1;
  		vi ng = graph[node];
  		for(auto n: ng) {
  			if(src.find(n)==src.end()) {
  				q.push({n,dist+1});
  				src.insert(n);
  			} 
  		} 
  	}
  	return -1;
  }
};

int main() {
	return 0;
}