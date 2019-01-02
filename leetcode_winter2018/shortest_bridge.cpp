#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pt;
typedef vector<pt> vt;
vi dx={-1,1,0,0};
vi dy={0,0,1,-1};
#define INF 0x3f3f3f3f

class Solution {
private:
	vt sa, sb;
public:
    int shortestBridge(vector<vector<int>>& A) {
    	int lr = A.size();
    	if(lr == 0) return 0;
    	int lc = A[0].size(), cmp{1}, ans{INF};
        for(int i=0; i<lr; i++){
        	for(int j=0; j<lc; j++){
        		if(A[i][j]!=0) {bfs(i,j,A,cmp); cmp++;}
        	}
        }
        for(auto& a:sa){
        	for(auto& b:sb) ans=min(ans,(abs(a.first-b.first)+abs(a.second-b.second)));
        }
    	return ans-1;

    }

    void bfs(int i, int j, vvi& A, int cmp){
    	int lr = A.size(), lc = A[0].size();
    	queue<pt> q;
    	A[i][j]=0;;
    	q.push({i,j});
    	cmp == 1 ? sa.push_back({i,j}) : sb.push_back({i,j});
    	while(!q.empty()){
    		pt cc=q.front();
    		q.pop();
    		for(int i=0;i<4;i++){
    			int x=dx[i]+cc.first;
    			int y=dy[i]+cc.second;
    			if(x>=0 && x<lc && y>=0 && y<lc && A[x][y]==1){
    				q.push({x,y});
    				A[x][y]=0;
    				cmp == 1 ? sa.push_back({x,y}) : sb.push_back({x,y});
    			}
    		}
    	}
    }
};

int main(){
	vvi test = {{1,1,0},{0,1,0},{0,0,1}};
	vvi test1 = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	Solution sln;
	int a = sln.shortestBridge(test1);
	cout<<a<<endl;
	return 0;
}