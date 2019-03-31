#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;
typedef pair<int,int> pt;
#define INF 0x3f3f3f3f 

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix){
  	int sr=matrix.size();
  	if(sr==0) return matrix;
  	int sc=matrix[0].size();
  	llst result(sr,lst(sc,INF));
      queue<pt> q;
      int dx[]={-1,1,0,0};
      int dy[]={0,0,-1,1};
      // some preprocessing
      for(int i=0;i<sr;i++){
      	for(int j=0;j<sc;j++){
      		if(matrix[i][j]==0){
      			result[i][j]=0;
      			q.push({i,j});
      		}
      	}
      }
      while(!q.empty()){
      	pt cc=q.front();
      	q.pop();
      	int cr=result[cc.first][cc.second];
      	for(int k=0;k<4;k++){
      		int x=cc.first+dx[k];
      		int y=cc.second+dy[k];
      		if(x>=0 && x<sr && y>=0 && y<sc && result[x][y]!=0){
      			if(result[x][y]>cr+1){
      				q.push({x,y});
      				result[x][y]=cr+1;
      			}
      		}	
      	}
      }
      return result;
  }
};

int main(){
	Solution sln;
	llst matrix={{0,0,0},{0,1,0},{1,1,1}};
	llst ans = sln.updateMatrix(matrix);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}