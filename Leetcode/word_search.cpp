#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<char>> vcc;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if(board.size()==0) return 0;
    	if(board[0].size()==0) return 0;
      return dfs(board,"",word,0,0);
    }

    bool dfs(vcc &b, string cr, string t, int r, int c) {
    	if(r<0 || c<0 || r>=b.size() || c>=b.size()) return false;
    	if(curr==target) return true;
    	bool a1 = dfs(b,cr+b[r-1][c],t,r-1,c);
    	bool a2 = dfs(b,cr+b[r+1][c],t,r+1,c);
    	bool a3 = dfs(b,cr+b[r][c-1],t,r,c-1);
    	bool a4 = dfs(b,cr+b[r][c+1],t,r,c+1);
    	return (a1||a2||a3||a4);
    }
};

int main() {
	return 0;
}