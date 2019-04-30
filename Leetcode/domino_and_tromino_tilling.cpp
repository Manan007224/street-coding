#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int numTilings(int N) {
  	if(N==0)
  		return 0;
  	vector<i64> dp(N+1);
  	int MOD = 1e9;
  	MOD += 7;
  	dp[1] = 1, dp[2] = 2, dp[3] = 5;
  	for(int i=4; i<=N; i++) {
  		dp[i] = 2*(dp[i-1]) + dp[i-3];
  		dp[i] = dp[i] % MOD;
  	}
  	return dp[N];
  }
};

int main() {
	Solution sln;
	cout << sln.numTilings(4) << endl;
	cout << sln.numTilings(5) << endl;
	cout << sln.numTilings(19) << endl;
	return 0;
}