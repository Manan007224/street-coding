#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &tp){
  int sz=tp.size();
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++)
      cout << tp[i][j] << " ";
    cout << endl;
  }
}

bool valid(vector<vector<int>> &board, int row, int col){
  int sz=board.size();
  for(int i=0;i<row;i++){
    if(board[i][col]==1)
      return false;
  }
  for(int i=row,j=col; i>=0&&j<sz; i--,j++){
    if(board[i][j]==1)
      return false;
  }
  for(int i=row,j=col; i>=0&&j>=0; i--,j--){
    if(board[i][j]==1)
      return false;
  }
  return true;
}

bool backtrack(vector<vector<int>> &board, int row){
  int sz=board.size();
  if(row==sz){
    print(board);
    return true;
  }
  bool ans = false;
  for(int k=0;k<sz;k++){
    if(valid(board, row, k)){
      board[row][k]=1;
      ans = backtrack(board, row+1) || ans;
      board[row][k]=0;
    }
  }
  return ans;
}

int main(){
  vector<vector<int>> board = {{0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0}};
  int ans = backtrack(board,0);
  return 0;
}
