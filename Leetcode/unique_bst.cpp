#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    int numTrees(int n) {
	    	vector<int>dp(n+1);
	    	dp[0] = 1;
	    	dp[1] = 1;
	    	for(int i=2;i<=n;i++){
	    		for(int j=0;j<i;j++){
	    			dp[i] = dp[i] + dp[j]*dp[i-j-1];
	    		}
	    	}
	    	return dp[n];
	    }
};

int main() {
	Solution sln;
	cout << sln.numTrees(5) << endl;
	return 0;
}