#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

int main() {
	int T; cin >> T;
	for(int t=0; t<T; t++) {
		int m, c; cin >> m >> c;
		vii G;
		for(int i=0; i<c; i++) {
			int k; cin >> k;
			vector<int> cr;
			for(int j=0; j<k; j++) cin >> cr[j];
			G.pb(cr);
		}	
		vector<vector<bool>> can_reach(m+1, vector<bool>(c+1, 0));
		for(int i=1; i<c; j++) {
			can_reach[m-G[0][i]][0] = 1;
		}
		for(int j=1; j<c; j++) {
			for(int i=0; i<m; i++) {
				if(can_reach[m][j-1]) {
					for(int k=0; k<G[j].size(); k++) {
						if(i - G[j][k] >= 0) {
							can_reach[i-G[j][k]][j] = 1;
						}
					}
				}
			}
		}
		// find the solution
		int res = -1;
		for(int i=0; i<=m; i++) {
			if(can_reach[i][c-1]){
				res = i;
				break;
			}
		}
		if(res > -1) cout << res << endl;
		else cout << "no solution" << endl;
	}
	return 0;
}