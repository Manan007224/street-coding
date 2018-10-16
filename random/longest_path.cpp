#include <bits/stdc++.h>
using namespace std;

int longestPath(vector < vector < int> > &matrix, int i, int j, vector< vector < int > > &dp) {
	int r = matrix.size();
	int c = matrix[0].size();
	if(i<0 || j<0 || i>=r || j>=c)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	else if(i<r-1 && matrix[i][j]+1==matrix[i+1][j])
		return dp[i][j] = 1 + longestPath(matrix,i+1,j,dp);
	else if(i>0 && matrix[i][j]+1==matrix[i-1][j])
		return dp[i][j] = 1 + longestPath(matrix,i-1,j,dp);
	else if(j<c-1 && matrix[i][j]+1==matrix[i][j+1])
		return dp[i][j] = 1 + longestPath(matrix,i,j+1,dp);
	else if(j>0 && matrix[i][j]+1==matrix[i][j-1])
		return dp[i][j] = 1 + longestPath(matrix,i,j-1,dp);
	else 
		return dp[i][j] = 1;
}


int main() {	
		vector<vector<int> >m {{1,2,9},{5,3,8},{4,6,7}};
		vector < vector < int> > dp(3, vector<int>(3,-1));
		int ans = 0;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(dp[i][j] == -1)
					longestPath(m,i,j,dp);
				ans = max(ans, dp[i][j]); 
			}
		}
		cout << "The Longest Path is: " << ans << endl;

}