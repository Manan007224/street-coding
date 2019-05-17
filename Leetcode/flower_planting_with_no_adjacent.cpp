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
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> graph(N);
    vector<int> res(N);
    for(auto p : paths) {
    	graph[p[0]].pb(p[1]);
    	graph[p[1]].pb(p[0]);
    }
    for(int i=0; i<N; i++) {
    	unordered_set<int> flowers = {1,2,3,4};
    	for(auto g: graph[i]) flowers.erase(res[g]);
    	res[i] = *(flowers.begin());
    }
    return res;
  }
};

int main() {
	return 0;
}