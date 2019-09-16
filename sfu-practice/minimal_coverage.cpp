#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void go(vii &res, vii &segs, vi &dp, int cnt) {
	if(segs[cnt][0] <= 0) return;
	for(int i=cnt-1; i>=0; i--) {
		if(segs[i][1] >= segs[cnt][0] && dp[i] + 1 == dp[cnt]) {
			res.push_back(segs[i]);
			go(res, segs, dp, i);
			break;
		}
	}
}

int main() {
	int t; cin >> t;
	while(t--) {
		int end; cin >> end;
		vii segs;
		while(1) {
			int s, e; cin >> s >> e; 
			if(!s && !e) break;
			segs.push_back({s, e});
		}
		int n = segs.size(), i = 0;
		vi dp(n, INT_MAX);
		sort(segs.begin(), segs.end());

		for(; i<n; i++) {
  		if(segs[i][0] > 0) break;
  		dp[i] = 1;
  	}

		for(; i<n; i++) {
			for(int j=0; j<i; j++) {
				if(segs[i][0] <= segs[j][1]) dp[i] = min(dp[i], dp[j]+1);
			}
		}

		int mn = INT_MAX;
		int idx = -1;
		for(int i=n-1; i>=0; i--) {
			if(segs[i][1] >= end) if(mn > dp[i]) mn = dp[i], idx = i;
		}
		if(mn == INT_MAX) cout << 0 << endl;
		else {
			vii res = {};
			res.push_back(segs[idx]);
			go(res, segs, dp, idx);
			reverse(res.begin(), res.end());
			cout << mn << endl;
			for(auto r: res) cout << r[0] << " " << r[1] << endl;
		}
		if(t) cout << endl;	 
	}
	return 0;
}