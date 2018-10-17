#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> llst;
typedef vector<bool> lst_b;

void replace(llst &M){
	int sz = M.size();
	lst_b row(sz,false);
	lst_b col(sz,false);
	for(int i=0; i<sz; i++){
		for(int j=0; j<sz; j++){
			if(M[i][j]==0){
				row[i]=true;
				col[j]=true;
			}
		}
	}
	for(int r=0;r<row.size();r++){
		if(row[r]){
			for(int i=0;i<sz;i++) M[r][i]=0;
		}
	}
	for(int c=0;c<col.size();c++){
		if(col[c]){
			for(int i=0;i<sz;i++) M[i][c]=0;
		}
	}
}

int main(){
	llst matrix = {{1,1,1,1},{1,1,1,0},{1,1,1,1},{2,2,2,0}};
	replace(matrix);
	for(int k=0; k<4; k++){
		for(auto c: matrix[k]) cout<<c<<" ";
		cout<<endl;
	}
	return 0;
}