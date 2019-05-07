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
  int numSquares(int n) {
  	vector<int> dp(n+1, INT_MAX);
  	dp[0] = 0;
  	for(int i=1; i<=n; i++) {
  		for(int j=i-1, k=1; j>=0; k++, j = i-(k*k)) {
  			dp[i] = min(dp[i], dp[j]+1);
  		}
  	}
  	return dp[n];    
  }
};

int main() {
	int n = 22, n1 = 1, n2 = 4;
	Solution sln;
	cout << sln.numSquares(n) << endl;
	cout << sln.numSquares(n1) << endl;
	cout << sln.numSquares(n2) << endl;
	return 0;
}