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
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(((maxChoosableInteger+1)*maxChoosableInteger)/2 < desiredTotal) return false;
    unordered_map<int,int> lookup;
    vector<bool> visited(maxChoosableInteger+1, 0);
    return go(lookup, visited, desiredTotal);
  }

  bool go(unordered_map<int,int> &lookup, vector<bool> &visited, int left) {
  	if(left<=0) return 0;
  	int n = visited.size();
  	int mask = 0;
  	for(int i=0; i<n; i++) {
  		mask <<= 1;
  		if(visited[i]) mask |= 1;
  	}
  	if(lookup.find(mask) != lookup.end()) return lookup[mask];
  	for(int i=1; i<n; i++) {
  		if(visited[i]) continue;
  		visited[i] = 1;
  		if(!go(lookup, visited, left-i)) {
  			lookup[mask] = 1;
  			// visited[i]=0;
  			return 1;
  		}
  		visited[i]=0;
  	}
  	return lookup[mask] = 0;
  }
};

int main() {
	Solution sln;
	cout << sln.canIWin(4, 9) << endl;
	return 0;
}