#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

// bool go(vii &dp, vii &grid, int r, int c, string path, string &res) {
// 	if(r<0 || c<0 || r>dp.size()-1 || c>dp.size()-1) return false;
// 	if(dp[r][c]==1 || dp[r][c]==0){
// 		if(r==dp.size()-1 && c==dp.size()-1) res=path;
// 		return dp[r][c];
// 	}
// 	if(grid[r][c]==2) return dp[r][c]=go(dp,grid,r,c+1,path+'E',res);
// 	if(grid[r][c]==3) return dp[r][c]=go(dp,grid,r+1,c,path+'S',res);
// 	return dp[r][c] = go(dp,grid,r+1,c,path+'S',res) || go(dp,grid,r,c+1,path+'E',res);
// }

int main() {	
	int t; cin>>t;
	for(int a=1; a<=t; a++) {
		int n; cin>>n;
		string path; cin>>path;
		string res=" ";
		for(auto p:path) p == 'E' ? res += 'S' : res += 'E';
		cout<<"Case #"<<a<<": "<<res<<endl;
	}
}