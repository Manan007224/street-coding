#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
typedef unordered_map<int, unordered_set<int>> Graph;
#define pb push_back
#define fi first
#define se second

class Solution {
public:

	int max_size = 100000;

  int deleteAndEarn(vector<int>& nums) {
  	vector<int> prefix(max_size+1, 0), dp(max_size+1, 0);
  	for(auto n: nums) prefix[n] += n;
  	dp[0] = 0;
  	dp[1] = prefix[1];
  	for(int i=2; i<=max_size; i++) {
  		dp[i] = max(dp[i-2]+prefix[i], dp[i-1]);
  	}
  	return dp[max_size];	  
  }
};

int main() {
	vector<int> a = {3,2,4};
	vector<int> b = {2,2,3,3,3,4};
	vector<int> c = {1,1,1,1};
	Solution sln;
	cout << sln.deleteAndEarn(a) << endl;
	cout << sln.deleteAndEarn(b) << endl;
	return 0;
}