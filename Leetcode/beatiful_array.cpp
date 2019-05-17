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
  vector<int> beautifulArray(int N) {
   	// vector<int> res = {1};
   	// while(res.size() < N) {
   	// 	vector<int> tp;
   	// 	int k = res.size();
   	// 	for(int i = 0; i < k; i++){
   	// 		if(res[i] * 2 <= N) tp.pb(res[i] * 2);
   	// 	}
   	// 	for(int i = 0; i < k; i++){
   	// 		if(res[i] * 2 - 1 <= N) tp.pb(res[i] * 2 - 1);
   	// 	}
   	// 	res = tp;
   	// }
   	vector<int> curr = {};
   	return go(N, N);	   
  }

  vector<int> go(int sz, int N) {
  	if(sz == 1) {
  		return {1};
  	}
  	(sz % 2 == 0) ? sz = sz/2 : sz = sz/2 + 1;
  	vector<int> prev = go(sz, N);
  	int k = prev.size();
  	vector<int> res;
		for(int i = 0; i < k; i++) {
			if(prev[i] * 2 <= N) res.pb(prev[i] * 2);
		}
		for(int i = 0; i < k; i++) {
			if(prev[i] * 2 - 1 <= N) res.pb(prev[i] * 2 - 1);
		}
		return res;
  }
};

int main() {
	Solution sln;
	vector<int> res = sln.beautifulArray(5);
	for(auto r : res) cout << r << endl;
	return 0;
}