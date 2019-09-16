#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
  	int mx = 1, n = nums.size();
  	vector<int> dp(n, 1), cnt(n, 1);
  	for(int i=0; i<n; i++) {
  		for(int j=0; j<i; j++) {
  			if(nums[j] < nums[i]) {
  				if(dp[j] >= dp[i]) dp[i] = dp[j]+1, cnt[i] = cnt[j];
   				else if(dp[j] + 1 == dp[i]) cnt[i] += cnt[j];
  			}
  		}
  		mx = max(mx, dp[i]);
  	}
  	int res = 0;
  	for(int i=0; i<n; i++) if(dp[i] == mx) res += cnt[i];
  	return res;
  }
};

int main() {
	vector<int> lis = {1,3,5,4,7};
	vector<int> lis1 = {2,2,2,2,2};
	vector<int> lis2 = {4,6,7,7};
	vector<int> lis3 = {1,2,4,3,5,4,7,2};
	Solution sln;
	cout << sln.findNumberOfLIS(lis) << endl;
	cout << sln.findNumberOfLIS(lis1) << endl;
	cout << sln.findNumberOfLIS(lis2) << endl;
	cout << sln.findNumberOfLIS(lis3) << endl;
	return 0;
}	