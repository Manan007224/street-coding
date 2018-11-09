#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> llst;
typedef vector<int> lst;

int knapsack(lst &v,lst &w,llst &dp,int i,int j){
	if(i==0||j==0) return 0;
	if(w[i]>j) return knapsack(v,w,dp,i-1,j);
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=max(v[i]+knapsack(v,w,dp,i-1,j-w[i]),knapsack(v,w,dp,i-1,j));
	return dp[i][j]=ans;
}

int main(){
	lst v={1,6,18,22,28};
	lst w={1,2,5,6,7};
	vector<vector<int>> dp(v.size(),vector<int>(12,-1));
	int cost=knapsack(v,w,dp,v.size()-1,11);
	cout<<cost<<endl;
}