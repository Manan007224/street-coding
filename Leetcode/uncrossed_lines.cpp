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
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size();
    if(m == 0 || n == 0) return 0;
    vii dp(m+1, vi(n+1, 0));
    for(int i = 1; i <= m; i++) {
    	for(int j = 1; j <= n; j++) 
    		dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[m][n];
  }
};

int main() {
	return 0;
}