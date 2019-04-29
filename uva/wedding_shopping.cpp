#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

vector<vector<int>> G;

int go(int money_left, int id, int total_money, vii &dp) {
	if(money_left < 0)
		return INT_MIN;
	if(id == G.size())
		return total_money - money_left;
	if(dp[money_left][id] != -1)
		return dp[money_left][id];
	int mx = INT_MIN;
	for(int i=0; i<G[id].size(); i++) {
		mx = max(go(money_left - G[id][i], id+1, total_money, dp), mx);
	}
	return dp[money_left][id] = mx;
}

int main() {
	int T; cin >> T;
	for(int t=0; t<T; t++) {
		int m, c; cin >> m >> c;
		G.clear();
		for(int i=0; i<c; i++) {
			int k; cin >> k;
			vector<int> cr;
			for(int j=0; j<k; j++) cin >> cr[j];
			G.pb(cr);
		}
		vii dp(m+1, vi(c+1, -1));
		int res = go(money_left, 0, m, dp);
		if(res >= 0) cout << res << endl;
		else cout << "no solution" << endl;
	}
	return 0;
}