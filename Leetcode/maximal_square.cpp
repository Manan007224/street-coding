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
  int maximalSquare(vector<vector<char>>& matrix) {
  	int r = matrix.size(), c = matrix[0].size();
  	vii dp(r, vi(c, 0));
  	int res = 0;
  	for(int i=0; i<r; i++) dp[i][0] = (matrix[i][0]=='0') ? 0 : 1, res = max(res, dp[i][0]);
  	for(int i=0; i<c; i++) dp[0][i] = (matrix[0][i]=='0') ? 0 : 1, res = max(res, dp[0][i]);
  	// cout << res << endl;
  	for(int i=1; i<r; i++) {
  		for(int j=1; j<c; j++) {
  			if(matrix[i][j]=='0') dp[i][j]=0;
  			else {
  				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
  				res = max(res, dp[i][j]);
  			}
  		}
  	}
  	// for(auto dd: dp) {
  	// 	for(auto d :dd) cout << d << " ";
  	// 	cout <<endl;
  	// }
  	return res*res;   
  }
};

int main() {
	vector<vector<char>> a = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	vector<vector<char>> b = {{'0','0','1','1','1'},{'1','0','1','1','1'},{'0','1','1','1','1'},{'1','0','1','1','1'}};
	Solution sln;
	cout << sln.maximalSquare(a) << endl;
	return 0;
}