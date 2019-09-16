#include <bits/stdc++.h>
using namespace std;

int dp[31][1001];
const int M = 1000000007;


class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
  	memset(dp, -1, sizeof(dp));
  	go(d, f, target);
  }

  int go(int d, int f, int t) {
  	if(d==0 && t==0) return 1; 
  	if(dp[d][t] != -1) return dp[d][t];
  	int res = 0;
  	for(int i=1; i<=f; i++) {
  		if(t-i>=0) {
  			res += go(d-1, f, t-i) % M;
  		}
  	}
  	return dp[d][t] = res;
  }
};

int main() {
	return 0;
}