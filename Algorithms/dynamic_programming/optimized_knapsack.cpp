/*
	Code for optimized knapsack. Normally knapsack takes 
	space of O(n*w) but this version takes space O(2*w). 
	Knapsack: Opt(i,w) = {if(wi>w) Opt(i,w) = Opt(i-1)(w) or
			  Opt(i,w) = {max(Opt(i-1,w), Opt(i-1,w-w[i])+v[i])}
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;

int main(){
	lst v={1,6,18,22,28};
	lst w={1,2,5,6,7};
	int v1=v.size(); int w1=w.size();
	int k=11;
	llst dp(2,lst(k+1,-1));
	for(auto x1:v){
		dp[0]=dp[1];
		for(auto x2:w){
			if(w[x1]>x2) dp[1][x2]=dp[0][x2];
			else dp[1][x2]=max(dp[0][x2],dp[0][w-w[x1]]+v[x1]);
		}
	}
	cout<<dp[1][w1]<<endl;
	return 0;
}