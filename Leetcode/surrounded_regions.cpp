#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second
vi dx = {-1,1,0,0};
vi dy = {0,0,-1,1};

class Solution {
public:
  void solve(vector<vector<char>>& board) {
  	int x = board.size();
  	if(x==0) return;
  	int y = board[0].size();
  	if(y==0) return;
  	for(int i=0; i<x; i++) {
  		if(board[i][0]=='O') dfs(board,i,0);
  		if(board[i][y-1]=='O') dfs(board,i,y-1);
  	}
  	for(int i=0; i<y; i++) {
  		if(board[0][i]=='O') dfs(board,0,i);
  		if(board[x-1][i]=='O') dfs(board,x-1,i);
  	}
  	for(int i=0; i<x; i++) {
  		for(int j=0; j<y; j++) {
  			if(board[i][j]=='#')
  				board[i][j] = 'O';
  			else if(board[i][j]=='O') 
  				board[i][j] = 'X';
  		}
  	}    
  }

  void dfs(vector<vector<char>> &board, int r, int c) {
  	board[r][c] = '#';
  	for(int i=0; i<4; i++) {
  		int x = dx[i]+r, y = dy[i]+c;
  		if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='#' || board[x][y]=='X')
  			continue;
  		dfs(board, x, y);
  	}
  }
};

int main() {
	vector<vector<char>> board = {{'X','X', 'X', 'X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	Solution sln;
	sln.solve(board);
	for(auto bb: board) {
		for(auto b: bb) cout << b << " " ;
		cout << endl;
	}
	return 0;
}