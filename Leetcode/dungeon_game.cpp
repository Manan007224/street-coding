#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    	int m = dungeon.size();
    	if(m==0) return 0;
    	int n = dungeon[0].size();
    	if(n==0) return 0;
        vii dp = dungeon;
        dp[m-1][n-1] = 1-dp[m-1][n-1];
        if(dp[m-1][n-1]<=0) dp[m-1][n-1] = 1;
        for(int i=m-2; i>=0; i--) {
        	dp[i][n-1] = dp[i+1][n-1]-dp[i][n-1];
        	if(dp[i][n-1]<0) dp[i][n-1] = 1; 
        }
        for(int i=n-2; i>=0; i--) {
        	dp[m-1][i] = dp[m-1][i+1]-dp[m-1][i];
        	if(dp[m-1][i]<0) dp[m-1][i] = 1;
        }
        for(int i=m-2; i>=0; i--) {
        	for(int j=n-2; j>=0; j--) {
        		int r = dp[i+1][j]-dp[i][j];
        		int d = dp[i][j+1]-dp[i][j];
        		if(r<=0) r=1;
        		if(d<=0) d=1;
        		dp[i][j] = min(r,d);
        	}
        }
        if(dp[0][0] == 0) dp[0][0] = 1;
        return dp[0][0];
    }
};

int main() {
	vii dg = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
	vii dg1 = {{-1,1}};
	Solution sln;
	cout << sln.calculateMinimumHP(dg1) << endl;
	return 0;
}
