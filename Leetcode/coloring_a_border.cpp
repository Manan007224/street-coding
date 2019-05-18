typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int cl, ocl, x, y;
  
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
  	cl = color;
 		ocl = grid[r0][c0];
 		x = r0, y = c0;
    vii g = grid;
  	vvb v(grid.size(), vb(grid[0].size(), 0));
  	bool res = dfs(g, v, r0, c0);
    return g;
  }

  bool dfs(vii &g, vvb &v, int r, int c) {
  	int m = g.size(), n = g[0].size();
  	if(r < 0 || r >= m || c < 0 || c >= n || g[r][c] != ocl) return 0;
 	 	if(v[r][c]) return 1;
 	 	v[r][c] = 1;
 	 	if(dfs(g,v,r+1,c) + dfs(g,v,r-1,c) + dfs(g,v,r,c+1)+ dfs(g,v,r,c-1) < 4)
 	 		grid[r][c] = cl;
 	 	return 1;
  }
};