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
  bool PredictTheWinner(vector<int>& nums) {
  	int n = nums.size();
  	vector<vector<pii>> dp(n, vector<pii>(n));
  	for(int i=0; i<n; i++) {
  		dp[i][i] = {nums[i], 0};
  	}
  	for(int k=1; k<n; k++) {
  		for(int i=0; i<n-k; i++) {
  			int j = i + k;
  			if(nums[i] + dp[i+1][j].se >= nums[j] + dp[i][j-1].se) {
  				dp[i][j] =  {nums[i] + dp[i+1][j].se, dp[i+1][j].fi };
  			}
  			else dp[i][j] = {nums[j] + dp[i][j-1].se, dp[i][j-1].fi};
  		}
  	}
  	return (dp[0][n-1].fi >= dp[0][n-1].se);
  }
};

int main() {
	vector<int> arr = {3,9,1,2};
	vector<int> arr1 = {1,5,2};
	Solution sln;
	cout << sln.PredictTheWinner(arr) << endl;
	return 0;
}