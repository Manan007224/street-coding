#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

int go(viii &dp, int b, int l, int r, viii &seq) {
	if(l > r) return 0;
	if(dp[b][l][r]) return dp[b][l][r];
	else {
		int mn = INF, s = -1;
		for(int i=l; i<=r; i++) {
			int ff = max(go(dp,b-1,l,i-1,seq)+i, go(dp,b,i+1,r,seq)+i);
			if(mn > ff) s = i, mn = ff;
		}
		if(s!=-1)
			seq[b][l][r] = s; 
		return dp[b][l][r] = mn;	
	}
}

void track(viii &seq, vi &res, int b, int l, int r, viii &dp, int L) {
	if(l<=r) {
		int cr = seq[b][l][r];
		if(cr!=0) res.push_back(cr);
		if(cr!=0 && cr+1<=L) {
			int x = dp[b-1][l][cr-1];
			int y = dp[b][cr+1][r];
			if(x>y)
				track(seq, res, b-1, l, cr-1, dp, L);
			else
				track(seq, res, b, cr+1, r, dp, L);
		}
	}
}

int main() {
	int a, b; 
	cin>>a>>b;
	viii dp(a+1,vii(b+1,vi(b+1))), seq(a+1,vii(b+1,vi(b+1)));
	for(int l=0; l<=b; l++) {
		for(int r=l; r<=b; r++) {
			dp[1][l][r] = (r*(r+1))/2-(l*(l-1))/2;
		}
	}
	int res = go(dp,a,1,b,seq);
	vi r;
	if(a == 1) {
		for(int i=1; i<=b; i++) r.push_back(i);
	}
	else
		track(seq, r, a, 1, b, dp, b);
	cout << res << " = sum { ";
	for(auto x: r) cout << x << " ";
	cout << "}" << endl;
	return 0;
}