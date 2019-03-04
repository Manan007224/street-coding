F#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;

int main(){
	lst v={1,6,18,22,28};
	lst w={1,2,5,6,7};
	int v1=v.size(); int w1=w.size();
	int k=11;
	llst dp(2,lst(k+1));
	
	for(int x1=1;x1<=v;x1++){
		dp[0]=dp[1];
		for(int x2=1;x2<=w;x2++){
			if(w[x1]>x2) dp[1][x2]=dp[0][x2];
			else dp[1][x2]=max(dp[0][x2],dp[0][w-w[x1]]+v[x1]);
		}
	}
	cout<<dp[1][w1]<<endl;
	return 0;
}