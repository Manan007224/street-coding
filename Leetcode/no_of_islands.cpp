#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,1,-1};

class Solution {
public:
	void bfs(vector<vector<char>>& grid, int i, int j){
    	queue<pt> q;
    	grid[i][j]='0';
    	q.push({i,j});
    	int row = grid.size();
        int col = grid[0].size();
    	while(!q.empty()){
    		pt now=q.front();
    		q.pop();
    		for(int i=0;i<4;i++){
    			int x=dx[i]+now.first;
    			int y=dy[i]+now.second;
    			if(x>=0 && x<row && y>=0 && y<col && grid[x][y]=='1'){
    				q.push({x,y});
    				grid[x][y]='0';
    			}
    		}
    	}
    }

    int numIslands(vector<vector<char>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(row==0 || col==0) return 0;
        int islands = 0;
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		if(grid[i][j]=='1'){
        			bfs(grid,i,j);
        			islands++;
        		}
        	}
        }
        return islands;
    }
};

int main(){
	vector<vector<char>> v={{'1','1','0','0','0'},
							{'1','1','0','0','0'},
							{'0','0','1','0','0'},
							{'0','0','0','1','1'}};
	Solution sln;
	cout<<sln.numIslands(v)<<endl;
	return 0;
}