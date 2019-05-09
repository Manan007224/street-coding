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
  int findLength(vector<int>& A, vector<int>& B) {
  	int m = A.size(), n = B.size(), res = 0;
  	if(m==0 || n==0) return 0;
  	vii dp(m+1, vi(n+1,0));
  	for(int i=1; i<=m; i++) {
  		for(int j=1; j<=n; j++) {
  			if(A[i-1] == B[j-1]) {
  				dp[i][j] = dp[i-1][j-1]+1;
  				res = max(res, dp[i][j]);
  			}
  		}
  	}
  	return res;    
  }
};

int main() {
	vector<int> a = {1,2,3,2,1}, b = {3,2,1,4,7};
	Solution sln;
	cout << sln.findLength(a, b) << endl;
	return 0;
}