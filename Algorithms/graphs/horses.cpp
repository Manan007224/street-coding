#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> llst;
typedef vector<vector<bool>> llst_b;
typedef vector<int> lst;
typedef vector<bool> lst_b;
typedef pair<int,int> pt;

lst r={-1,-1,-2,-2,1,1,2,2};
lst c={-2,2,-1,1,-2,2,-1,1};

void print(llst tp){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)
			cout<<tp[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	llst_b v(8,lst_b(8,false));
	llst board(8,lst(8));
	board[0][0]=0;
	v[0][0]=true;
	queue<pt> q;
	pt temp;
	temp.first=0; temp.second=0;
	q.push(temp);
	while(!q.empty()){
		pt curr=q.front();
		int f=curr.first;
		int s=curr.second;
		q.pop();
		for(int k=0;k<8;k++){
			int a1=f+r[k];
			int a2=s+c[k];
			if(a1>=0&&a1<8&&a2>=0&&a2<8&&!v[a1][a2]){
				pt temp1;
				temp1.first=a1; temp1.second=a2;
				q.push(temp1);
				v[a1][a2]=true;
				board[a1][a2]=1+board[f][s];
			}	
		}
	}
	print(board);
	return 0;
}