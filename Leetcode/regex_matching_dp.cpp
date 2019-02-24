#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main(){
	string s="aab"; 
	string p="a*b";
	int ls=s.size();
	int lp=p.size();
	vvb dp(ls+1,vb(lp+1));
	for(int i=1;i<=ls;i++) dp[i][0]=false;
	dp[0][0]=true;
	for(int i=0;i<=ls;i++){
		for(int j=1;j<=lp;j++){
			bool ans=false;
			if(j+1<=lp && p[j+1]=='*'){
				if(s[i]==p[j] || p[j]=='.') ans = (i-1) && (ans || dp[i-1][j]);
				ans = (j-2>=0) && (ans || dp[i][j-2]);
			}
			else if(s[i]==p[j] || p[j]=='.') ans = (i-1>=0) && (ans || dp[i-1][j-1]);
			dp[i][j]=ans;
		}
	}
	cout<<dp[ls+1][lp+1]<<endl;
	return 0;
}