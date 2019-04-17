#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define pp pop_back
#define fi first
#define se second

vi dx = {1,1,2,2,-1,-1,-2,-2,1,1,3,3,-1,-1,-3,-3};
vi dy = {2,-2,1,-1,2,-2,1,-1,3,-3,1,-1,3,-3,1,-1};

bool dfs(int i, int j, int left, int I, int J, vector<vector<bool>> &V, vector<pii> &path) {
	// cout << i << " " << j << " " << left << endl;
	if(left == 0) return 1;
	for(int x=0; x<dx.size(); x++) {
		int r = dx[x]+i, c = dy[x]+j;
		if(r>=0 && c>=0 && r<I && c<J && !V[r][c]) {	
			path.pb({r,c});
			V[i][j] = 1;
			if(dfs(r,c,left-1,I,J,V,path)) return 1;
			path.pp();
			V[i][j] = 0;
		} 
	}
	return 0;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int r,c; cin>>r>>c;
		vector<pii> path;
		vector<vector<bool>> visited(r,vector<bool>(c,0));
		path.pb({0,0});
		visited[0][0] = 1;
		bool ans = dfs(0,0,(r*c)-1,r,c,visited,path);
		if(ans) {
			cout << "POSSIBLE" << endl;
			for(auto p: path) cout << (p.fi)+1 << " " << (p.se)+1 << endl;
		}
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}