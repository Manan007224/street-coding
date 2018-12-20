
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
vector<vector<ll>> dp;

int func(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i==j || j==0) return 1;
	if(i==j+1 || j==1) return i;
	//if(i<j) cout<<"stupid: "<<i<<", "<<j<<endl;
	return dp[i][j] = (func(i,j-1) + func(i,j-1)) % MOD;
}

int main(){
	int n,k; cin>>n>>k;
	
	unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		int a; cin>>a; m[a]++;
	}
	if(m.size()<k) cout<<0<<endl;
	else{
		n=m.size();
		dp=vector<vector<ll>>(n+1, vector<ll>(k+1, -1));
		//for(int i=0;i<=n;i++) dp[i][0]=1;
		//for(int i=0;i<=n;i++) dp[i][1]=i;
		//for(int i=0;i<=n;i++) dp[i][i]=1;
		//for(int i=1;i<=n;i++){
		//	for(int j=2;j<=i;j++){
		//		dp[i][j]=(func(i-1,j)+func(i-1,j-1))%MOD;
		//	}
		//}
		
		ll val = func(m.size(),k);
		for(auto& x: m){
			val = (val*x.second)% MOD;
		}
		cout<<val<<endl;
	}
}

