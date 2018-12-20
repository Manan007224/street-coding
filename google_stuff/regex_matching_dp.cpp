#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main(){
	string s,p;
	cin>>s>>p;
	int ls=s.size();
	int lp=p.size();
	vvb dp(ls,vb(lp+1));
	dp[0][0] = true;
	for(int i=1;i<=lp;i++) dp[0][i]=false;
	for(int i=0;i<ls;i++){
		for(int j=1;j<lp;j++){
			bool ans=false;
			if(j+1<lp && p[j+1]=='*'){
				if(s[i]==p[j] || p[j]=='.')
					ans = (j-2>=0) && (i-1>=0) && (ans || dp[i][j-2]);
				ans=(i-1>=0) && (ans || dp[i-1][j]);
			}
			else if(p[j]==s[i] || p[j]=='.')	
				ans=(i-1>=0) && (ans || dp[i-1][j-1]);
			dp[i][j]=ans;
		}
	}
	if(dp[ls-1][lp-1]) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	return 0;
}