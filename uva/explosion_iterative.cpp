#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<int> vi;

int dp[11][101][101], seq[11][101][101];

int main() {
	int a, f;
	cin >> a >> f;
	for(int l=0; l<=f; l++) {
		for(int r=l; r<=f; r++) {
			dp[1][l][r] = (r*(r+1))/2-(l*(l-1))/2;
		}
	}
	for(int b=2; b<=a; b++) {
		for(int l=f; l>=1; l--) {
			for(int r=f; r>=l; r--) {
				int mn = INF, s = -1;
				for(int x=l; x<=r; x++) {
						int ff = max(dp[b-1][l][x-1]+x, dp[b][x+1][r]+x);
						if(mn > ff) s = x, mn = ff;
				}
				if(s!=-1)
					seq[b][l][r] = s;
				dp[b][l][r] = mn;
			}
		} 
	}
	int l = 1, r = f, b = a;
	vi res;
	if(a!=1) {
		while(l<=r) {
			int t = seq[b][l][r];
			if(t!=0) res.push_back(t);
			if(t!=0 && t <= f) {
				if(dp[b-1][l][t-1] > dp[b][t+1][r])
					b--, r=t-1;
				else
					l=t+1;
			}
		}
	}
	else {
		for(int i=1; i<=f; i++) res.push_back(i);
	}
	cout << dp[a][1][f] << endl;
	for(auto r: res) cout << r << endl;
	return 0;
}
