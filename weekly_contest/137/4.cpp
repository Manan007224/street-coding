#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
  	int n = stones.size();
  	int sum = 0;
  	for(auto s: stones) sum += s;
  	vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
  	for(int i = 0; i <= n; ++i) dp[i][0] = 1;
  	for(int i = 0; i <= sum; ++i) dp[0][i] = 0;
  	dp[0][0] = 1;
  	for(int i = 1; i <= n; ++i) {
  		for(int j = 1; j <= sum; ++j) {
  			if(stones[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
  			else dp[i][j] = dp[i-1][j];
  		}
  	}
  	int t = sum/2;
  	int res = INT_MAX;
  	for(int i = t; i >= 0; i--) {
  		if(dp[n][i]) {
  			res = sum - (2*i);
  			break;
  		}
  	}
  	return res == INT_MAX ? 0 : res;
  }
};

int main() {
	vector<int> arr = {2,7,4,1,8,1};
	vector<int> arr1 = {1,2};
	Solution sln;
	cout << sln.lastStoneWeightII(arr1) << endl;
	return 0;
}