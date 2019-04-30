#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
  	if(nums.size()==0)
  		return 0;
  	sort(nums.begin(), nums.end());
  	vector<i64> dp(target+1, 0);
  	dp[0] = 1;
		for(int i=1; i<=target; i++) {
  		for(int j=0; j<nums.size(); j++) {
  			if(nums[j] <= i)
  				dp[i] += dp[i-nums[j]]; 
  		}
  	}
  	return dp[target];  
  }
};

int main() {
	Solution sln;
	vector<int> t = {1,2,3};
	cout << sln.combinationSum4(t, 4) << endl;
	return 0;
}