#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

int go(viii &dp, int b, int l, int r, viii &seq, int L) {
	if(l > r) return 0;
	if(l < 1 || r > L || b < 1) return 0;
	if(b == 1) {
		return (r*(r+1))/2-(l*(l-1))/2;
	}
	else {
		int mn = INF, s = -1;
		for(int i=l; i<=r; i++) {
			int ff = max(go(dp,b-1,l,i-1,seq,L)+i, go(dp,b,i+1,r,seq,L)+i);
			if(mn > ff) s = i, mn = ff;
		}
		if(s!=-1)
			seq[b][l][r] = s, dp[b][l][r] = s; 
		return mn;	
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
	int res = go(dp,a,1,b,seq,b);
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