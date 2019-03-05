#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 0x3f3f3f3f

int opt(vi& cuts, vvi& dp, int lo, int hi){
	if(hi-lo <= 1) return 0;
	if(dp[lo][hi]!=INF) return dp[lo][hi];
	int res {INF};
	for(int i=lo+1; i<hi; i++){
		res = min(res,opt(cuts,dp,lo,i)+opt(cuts,dp,i,hi)+cuts[hi]-cuts[lo]);
	}
	return dp[lo][hi]=res;
}

int main(){
	while(1){
		int l,n,k{1};
		cin>>l; if(l==0) break;
		cin >> n;
		vi cuts(n+2);
		vvi dp(n+2,vi(n+2,INF));
		cuts[0] = 0, cuts[n+1] = l;
		for(int i=1; i<n+1; i++) cin>>cuts[i];
		cout<<"The minimum cutting is "<<opt(cuts,dp,0,n+1)<<"."<<endl;
	}
	return 0;
}