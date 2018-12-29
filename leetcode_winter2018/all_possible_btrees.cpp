#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;

class Solution {
public:
    int numTrees(int n) {
    	lst dp(n+1,0);
        dp[0]=1; dp[1]=1;
    	for(int i=2;i<=n;i++){
            for(int k=0;k<i;k++){
                dp[i]=dp[i]+(dp[k]*dp[i-k-1]);
            }
        }
    	return dp[n];
    }
};

int main(){
	Solution sln;
	cout<<sln.numTrees(4)<<endl;
	return 0;
}