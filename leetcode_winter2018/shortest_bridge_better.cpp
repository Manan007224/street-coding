#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pt;
vi dx={-1,1,0,0};
vi dy={0,0,-1,1};

class Solution{
public:
    int shortestBridge(vector<vector<int>>& A){
    	int lr = A.size();
    	if(lr == 0) return 0;
    	int lc = A[0].size();
    	vvb V(lr,vb(lc,false));
    	queue<pt> q;
    	auto ss=find_first(A,lr,lc);
    	dfs(ss.first,ss.second,A,q,V);
    	return bfs(A,V,q);
    }

    pt find_first(vvi& A,int lr,int lc){
    	for(int i=0;i<lr;i++){
    		for(int j=0;j<lc;j++){ if(A[i][j]==1) return {i,j}; }
    	}
    }

    int bfs(vvi& A, vvb& V, queue<pt>& q){
        int bridge=0;
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
                auto cc=q.front();
                if(A[cc.first][cc.second]==1) return bridge-1;
                q.pop();
                for(int k=0;k<4;k++){
                    int x=dx[k]+cc.first;
                    int y=dy[k]+cc.second;
                    if(x>=0 && x<lr && y>=0 && y<lc && V[x][y]==0){
                        V[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            bridge++;
        }
    }

    void dfs(int i,int j, vvi& A, queue<pt>& q, vvb& V){
    	A[i][j]=2;
    	V[i][j]=1;
    	int lr=V.size(), lc=V[0].size();
    	q.push({i,j});
    	for(int k=0;k<4;k++){
    		int x=dx[k]+i;
    		int y=dy[k]+j;
    		if(x>=0 && x<lr && y>=0 && y<lc && A[x][y]!=0 && A[x][y]!=2) dfs(x,y,A,q,V); 
    	}
    }
};

int main(){
	vvi test = {{1,1,0},{0,1,0},{0,0,1}};
	vvi test1 = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	Solution sln;
	int a = sln.shortestBridge(test);
	cout<<a<<endl;
	return 0;
}