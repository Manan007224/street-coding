#include <bits/stdc++.h>
using namespace std;

int maxPath(vector< vector<int > > &v, int r, int c,vector< vector<int > > &dp) {
	
	if(r<0 || r>2|| c<0 || c>2) 
		return 0;
	else if(dp[r][c] !=-1)
		return dp[r][c];
	else if(r == 2 && c==0)
		return v[r][c];
	else
		return dp[r][c] = v[r][c] + max(maxPath(v,r,c-1,dp), maxPath(v,r,c+1,dp));
		cout << "For this" << r << " " << c << " " << dp[r][c] << endl;
		// return v[r][c] + max(maxPath(v,r,c-1,targetR, targetC), maxPath(v,r+1,c, targetR, targetC));
}

int main() {
	vector< vector< int > > m = {{1,1,3},
							 	{2,2,1},		
							 	{0,3,2}};
	vector < vector < int> > dp(3, vector<int>(3,-1));
	int op = maxPath(m,0,2,dp);
	cout << op << endl;
	return 0;
}