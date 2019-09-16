#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
  	int r = grid.size(), c = grid[0].size();
    vector<vector<int>> nr(r, vector<int>(c, INT_MAX));
    queue<pair<int,int>> q;
    for(int i=0; i<r; i++)
    	for(int j=0; j<c; j++)
    		if(grid[i][j]) q.push({i, j}), nr[i][j] = 0;
    while(!q.empty()) {
    	auto k = q.front();
    	q.pop();
    	for(int i=0; i<4; i++) {
    		int x = k.first + dx[i];
    		int y = k.second + dy[i];
    		if(x>=0 && y>=0 && x<r && y<c && grid[x][y] != 1) {
    			int dist = abs(k.first - x) + abs(k.second - y) + nr[k.first][k.second];
    			if(nr[x][y] > dist) {
    				nr[x][y] = dist;
    				q.push({x, y});
    			}
    		}
    	}
    }
    int res = -1;
    for(int i=0; i<r; i++) {
    	for(int j=0; j<c; j++) if(!grid[i][j]) res = max(res, nr[i][j]);
    }
    return res;
  }
};


int main() {
	vector<vector<int>> v = {{1,0,1},{0,0,0},{1,0,1}};
	Solution sln;
	cout << sln.maxDistance(v) << endl;
	return 0;
}