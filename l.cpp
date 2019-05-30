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
  bool canPartition(vector<int>& nums) {
  	int n = nums.size();
  	int sum = 0;
  	for(auto n: nums) sum += n;
  	// if(sum % 2 != 0) return false;
  	sum /= 2;
  	vector<vector<bool>> dp(n+1, vector<bool>(sum+1, 0));
  	for(int i=0; i<=n; i++) dp[i][0]=1;
  	for(int i=1; i<=sum; i++) dp[0][i]=0;
  	for(int i=1; i<=n; i++) {
  		for(int j=1; j<=sum; j++) {
  			dp[i][j] = dp[i-1][j];
  			if(j>=nums[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
  		}
  	}
  	return dp[n][sum];
  }
};


int main() {
  Solution sln;
  vector<int> arr = {1,6,5,11};
  cout << sln.canPartition(arr) << endl;
  return 0;
}