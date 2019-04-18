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

  int cherryPickup(vector<vector<int>>& grid) {
  	vii dp(grid.size(), vi(grid[0].size(),-2));
  	vii dp1(grid.size(), vi(grid[0].size(),-2));
  	int first_pass = gof(grid, dp, 0, 0);
  	if(first_pass == -1) return 0;
  	backtrack(grid, dp, 0, 0);
  	int second_pass = gos(grid, dp, grid.size()-1, grid[0].size()-1);
  	return first_pass+second_pass;
  }

  int gof(vii &grid, vii &dp, int r, int c) {
  	if(r<0 || c<0 || c>grid[0].size()-1 || r>grid.size()-1) return -1;
  	if(r==grid.size()-1 && c==grid[0].size()-1) return dp[r][c]=grid[r][c];
  	if(grid[r][c]==-1) return dp[r][c]=-1;
  	if(dp[r][c]!=-2) return dp[r][c];
  	int up = gof(grid, dp, r+1, c);
  	int down = gof(grid, dp, r, c+1);
  	if(up==-1 && down==-1) return dp[r][c]=-1;
  	return dp[r][c]=grid[r][c]+max(up,down); 	
  }

  void backtrack(vii &grid, vii &dp, int r, int c) {
  	if(r>=grid.size() || c>=grid[0].size() || r<0 || c<0) return;
  	int ff = (r < grid.size()-1) ? dp[r+1][c] : INT_MIN;
  	int ss = (c < grid[0].size()-1) ? dp[r][c+1] : INT_MIN;
 		ff > ss ? r++ : c++;
 		grid[r][c] = 0;
 		backtrack(grid, dp, r, c); 	
  }

  int gos(vii &grid, vii &dp, int r, int c) {
  	if(r<0 || c<0 || c>grid[0].size()-1 || r>grid.size()-1) return -1;
  	if(r==0 && c==0) return dp[r][c]=grid[r][c];
  	if(grid[r][c]==-1) return -1;
  	if(dp[r][c]!=-2) return dp[r][c];
  	int up = gos(grid, dp, r-1, c);
  	int down = gos(grid, dp, r, c-1);
  	if(up==-1 && down==-1) return dp[r][c]=-1;
  	return dp[r][c]=grid[r][c]+max(up,down); 
 	}
};

int main() {
	vii grid = {{0,1,-1},{1,0,-1},{1,1,1}};
	Solution sln;
	cout << sln.cherryPickup(grid) << endl;
	return 0;
}