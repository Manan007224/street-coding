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
  int maxCoins(vector<int>& nums) {
  	int n = nums.size();
  	vii dp(n, vi(n,0));
  	int ans =  go(dp, 0, n-1, nums);
  	return ans;	    
  }

  int go(vii &dp, int left, int right, vi &arr) {
  	int n = arr.size();
  	if(left > right) return 0;
  	if(dp[left][right]!=0) return dp[left][right];
  	int x = (left-1>=0) ? arr[left-1] : 1;
  	int y = (right+1<n) ? arr[right+1] : 1;
  	for(int cut = left; cut <= right; cut++) {
  		dp[left][right] = max(dp[left][right], x*y*arr[cut] + go(dp,left,cut-1,arr) + go(dp,cut+1,right,arr));
  	}
  	return dp[left][right];
  }
};

class Solution {
public:
	int maxCoins(vector<int> &nums) {
		int n = nums.size();
		vii dp(n, )
		for(int )
	}
};

int main() {
	vector<int> arr = {3,1,5,8};
	Solution sln;
	cout << sln.maxCoins(arr) << endl;
	return 0;
}