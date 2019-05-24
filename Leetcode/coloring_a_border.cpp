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
  int ir, ic, r, c, color;
  vvb v, g;
  vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    g = grid;
    color = grid[r0][c0];
    r = grid.size(), c = grid[0].size();
    v = vvb(r, vb(c));
    dfs(r, c);
  }

  bool dfs(int x, int y) {
    if(x<0 || y<0 || x>=r || y>=c) return 0;
    bool is_border = 0, not_same = 0;
    v[x][y] = 1;
    if(x==0 || x==r-1 || y==0 || y==c-1) is_border=1;
    for(int i=1; i<4; i++) {
      int xx = dir[i].fi + x, yy = dir[i].se + y;
      if(!v[xx][yy] && g[xx][yy]=g[x][y]) {
        if(!dfs(xx,yy)) not_same = 1;
      }
    }
    if(not_same || is_border) {
      g[x][y] = color;
      return 1;
    }
    return 0;
  }
};