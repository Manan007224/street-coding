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
  int mincostTickets(vector<int>& days, vector<int>& costs) {
  	int n = days.size(), md = 366;
  	vector<int> dp(md, 0);
  	vector<bool> vis(md, 0);
  	for(int i=0; i<n; i++) vis[days[i]] = 1;
  	for(int i=1; i<md; i++) {
  		if(!vis[i]){
  			dp[i] = dp[i-1];
  			continue;
  		}
  		int x = (i-7>=0) ? dp[i-7] : 0;
  		int y = (i-30>=0) ? dp[i-30] : 0; 
  		dp[i] = min({costs[0]+dp[i-1], costs[1]+x, costs[2]+y});
  	}
  	cout << dp[7] << endl;
  	return dp[md-1];
  }
};

int main() {
	vector<int> arr = {1,4,6,7,8,20};
	vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10,30,31};
	vector<int> cost = {2,7,15}, cost1 = {7,2,15};
	Solution sln;
	cout << sln.mincostTickets(arr, cost1) << endl;
	return 0;
}