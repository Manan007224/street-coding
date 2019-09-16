#include <bits/stdc++.h>
using namespace std;

int go(vector<vector<int>> &dp, vector<vector<int>> &mx, int i, int j) {
	if(i==j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INT_MAX;
	for(int k=i; k<j; k++)
		dp[i][j] = min(dp[i][j], mx[k+1][j]*mx[i][k] + go(dp,mx,i,k) + go(dp,mx,k+1,j));
	return dp[i][j];
}

int solve(vector<int> &arr) {
	int n = arr.size();
	vector<vector<int>> mx(n, vector<int>(n, 0));
	vector<vector<int>> dp(n, vector<int>(n, -1));
	for(int i=0; i<n; i++) {
		mx[i][i] = arr[i];
		for(int j=i; j<n; j++)
			mx[i][j] = max(mx[i][j-1], arr[j]);	
	}
	return go(dp, mx, 0, n-1);
}

int main() {
	vector<int> arr = {6, 2, 4};
	cout << solve(arr) << endl;
	return 0;
}