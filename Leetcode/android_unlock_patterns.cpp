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
  int numberOfPatterns(int m, int n) {
  	vii dp(10,vi(10,0));
		dp[1][3] = dp[3][1] = 2;
		dp[1][7] = dp[7][1] = 4;
		dp[3][9] = dp[9][3] = 6;
		dp[7][9] = dp[9][7] = 8;
		dp[4][6] = dp[6][4] = 5;
		dp[1][9] = dp[9][1] = 5;
		dp[2][8] = dp[8][2] = 5;
		dp[3][7] = dp[7][3] = 5;
  	int res = 0;
  	vector<bool> v(10,0);
    for(int i=m; i<=n; ++i) {
    	res += dfs(1,i-1,v,dp)*4 + dfs(2,i-1,v,dp)*4 + dfs(5,i-1,v,dp);
    }
    return res;  
  }
  int dfs(int start, int rem, vector<bool> &v, vii &dp) {
  	if(rem < 0) return 0;
  	if(rem == 0) return 1;
  	v[start] = 1;
  	int res = 0;
  	for(int i=1; i<=9; ++i) {
  		if(!v[i] && (dp[start][i]==0 || v[dp[start][i]])) {
  			res += dfs(i,rem-1,v,dp);
  		}
  	}
  	v[start] = 0;
  	return res;
  }
};

int main() {
	Solution sln;
	cout << sln.numberOfPatterns(1,1) << endl;
	cout << sln.numberOfPatterns(1,4) << endl;
	cout << sln.numberOfPatterns(1,2) << endl;
	cout << sln.numberOfPatterns(3,6) << endl;
	cout << sln.numberOfPatterns(4,9) << endl;
	return 0;
}