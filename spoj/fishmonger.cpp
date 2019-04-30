#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef vector<vector<pii>> vpi;
typedef long long i64;
#define inf 0x3f3f3f3f 
#define pb push_back
#define fi first
#define se second

pii go(vii &TM, vii &TT, vpi &dp, int curr_city, int time_left) {
	if(time_left < 0)
		return {inf, inf};
	if(curr_city == TM.size()-1)
		return {0,0};
	if(dp[curr_city][time_left].fi != -1)
		return dp[curr_city][time_left];

	pii res = {inf, inf};
	for(int n = 0; n < TM.size(); n++) {
		if(n != curr_city) {
			pii next_city = go(TM, TT, dp, n, time_left - TM[curr_city][n]);
			if(next_city.fi + TT[curr_city][n] < res.fi ){
				res.fi = next_city.fi + TT[curr_city][n];
				res.se = next_city.se + TM[curr_city][n];
			}
		}
	}
	return dp[curr_city][time_left] = res;
}

int main() {
	while(true) {
		int n, t; cin >> n >> t;
		if(n==0 && t==0)
			break;
		vii TM(n, vi(n)), TT(n, vi(n));
		vector<vector<pii>> dp(n, vector<pii>(n, {-1,-1}));
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) cin >> TM[i][j];
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) cin >> TT[i][j];
		}
		pii res = go(TM, TT, dp, 0, t);
		cout << res.fi << " " << res.se << endl;
	}
	return 0;
}