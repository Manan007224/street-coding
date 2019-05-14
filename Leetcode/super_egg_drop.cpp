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
  int superEggDrop(int K, int N) {
  	vii dp(K+1, vi(N+1, -1));
  	for(int i=1; i<=N; i++) dp[1][i] = i;
  	for(int i=0; i<=K; i++) dp[i][0] = 0;
  	dp[0][0] = 0;
  	return go(dp, K, N);
  }

  int go(vii &dp, int e, int f) {
  	if(dp[e][f]!=-1) return dp[e][f];
  	int mn = f;
  	int lo = 1, hi = f, mid, left, right;
  	while(lo < hi) {
  		mid = lo + (hi-lo)/2;
  		left = go(dp, e-1, mid-1);
  		right = go(dp, e, f-mid);
  		mn = min(mn, 1+max(left, right));
  		if(left == right) break;
  		left < right ? lo = mid+1 : hi = mid;
  	}
  	return dp[e][f]=mn; 	
  }
};

int main() {
	Solution sln;
	cout << sln.superEggDrop(4, 20) << endl;
	return 0;
}