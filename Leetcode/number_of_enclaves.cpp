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
vector<int> dx = {1,-1,0,0};
vector<int> dy = {0,0,-1,1};

class Solution {
public:
  int numEnclaves(vector<vector<int>>& A) {
  	int m = A.size(), n = A[0].size(), res = 0;
  	vii vis(m, vi(n, 0));
  	for(int i=0; i<m; i++) {
  		if(A[i][0]==1 && !vis[i][0]) dfs(i, 0, vis, A);
  		if(A[i][n-1]==1 && !vis[i][n-1]) dfs(i, n-1, vis, A);
  	}
  	for(int i=0; i<n; i++) {
  		if(A[0][i]==1 && !vis[0][i]) dfs(0, i, vis, A);
  		if(A[m-1][i]==1 && !vis[m-1][i]) dfs(m-1, i, vis, A);
  	}
  	for(int i=0; i<m; i++) {
  		for(int j=0; j<n; j++) if(A[i][j]==1 && !vis[i][j]) res++;
  	}
  	return res;
  }

  void dfs(int i, int j, vii &vis, vii &A) {
  	int m = A.size(), n = A[0].size();
  	vis[i][j]=1;
  	for(int k=0; k<4; k++) {
  		int x = dx[k]+i, y = dy[k]+j;
  		if(x>=0 && y>=0 && x<m && y<n && A[i][j]==1 && !vis[x][y]) dfs(x,y,vis,A);
  	}
  }
};

int main() {
	vii arr = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
	Solution sln;
	cout << sln.numEnclaves(arr) << endl;
	return 0;
}