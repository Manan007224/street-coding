#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
typedef long long ll;
vector<vector<ll>> digits={{4,6},{6,8},{7,9},{4,8},{3,9,0},
{},{1,7,0},{2,6},{1,3},{2,4}};

class Solution {
public:
    int knightDialer(int N) {
    	if(N==0) return 0;
    	if(N==1) return 10;
        vector<vector<ll>> dp(N,vector<ll>(10,0));
        for(int i=0;i<10;i++) dp[0][i]=1;
        for(int i=1;i<N;i++){
        	for(int k=0;k<=9;k++){
        		for(auto d:digits[k]) 
        			dp[i][k]+=(dp[i-1][d])%M;
        	}
        }
        return accumulate(dp[N-1].begin(),dp[N-1].end(),0LL)%M;
    }	
};

int main(){
	Solution sln;
	cout<<sln.knightDialer(161)<<endl;
	return 0;
}