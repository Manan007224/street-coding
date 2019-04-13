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
  int findPaths(int m, int n, int N, int i, int j) {
  	vector<vii> dp(N+1, vii(m, vi(n,0)));
  	const int MOD = 1000000000+7;
  	for(int k=1; k<=N; k++) {
  		for(int x=0; x<m; x++) {
  			for(int y=0; y<n; y++) {
  				dp[k][x][y] = ((x == 0 ? 1 : dp[k-1][x][y]) % MOD) + 
  											((x == m-1 ? 1 : dp[k-1][x+1][y])) + 
  											((y == 0 ? 1 : dp[k-1][x][y-1]) % MOD) + 
  											((y == n-1 ? 1 : dp[k-1][x][y+1]) % MOD);
  			}
  		}
  	}
  	return dp[N][i][j];	     
  }
};

int main() {
	Solution sln;
	cout << sln.findPaths(2,2,2,0,0) << endl;
	cout << sln.findPaths(1,3,3,0,1) << endl;
	return 0;
}