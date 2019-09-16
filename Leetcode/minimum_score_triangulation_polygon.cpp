#include <bits/stdc++.h>
using namespace std;

int dp[50][50];


class Solution {
public:
  int minScoreTriangulation(vector<int>& A) {
  	memset(dp, -1, sizeof(dp));
  	return go(0, A.size()-1, A);  
  }

  int go(int i, int j, vector<int> &A) {
		if(abs(i-j) < 2) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		int mx = INT_MAX;
		for(int k=i+1; k<j; k++) {
			mx = min(mx, A[i]*A[j]*A[k] + go(i,k,A) + go(k,j,A));
		}
		dp[i][j] = mx;
		return dp[i][j];
	}
};

int main() {
	Solution sln;
	vector<int> test = {1,3,1,4,1,5};
	cout << sln.minScoreTriangulation(test) << endl;
	return 0;
}