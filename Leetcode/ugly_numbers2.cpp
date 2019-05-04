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
  int nthUglyNumber(int n) {
  	int two = 0, three = 0, five = 0;
  	vector<int> dp(n);
  	dp[0] = 1;
  	for(int i=1; i<n; i++) {
  		dp[i] = min({dp[two]*2, dp[three]*3, dp[five]*5});
  		if(dp[i] == dp[two] * 2) two++;
  		else if(dp[i] == dp[three] * 3) three++;
  		else if(dp[i] == dp[five] * 5) five++;
  	}
  	return dp[n-1];
  }
};

int main() {
	Solution sln;
	cout << sln.nthUglyNumber(10) << endl;
	return 0;
}