#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int coinChange(vector<int> &coins, int amount){
		if(amount==0) return 0;
		sort(coins.begin(),coins.end());
		if(coins[0]>amount)
			return -1;
		map<int,int> dp;
		for(auto c: coins)
			dp[c]=1;
		int ans=runner(dp,coins,amount);
		return ans;
	}
	int runner(map<int,int> &dp, vector<int> &coins, int value){
		if(value<0) return -1;
		if(value==0) return 0;
		if(dp.find(value)!=dp.end())
			return dp[value];
		int mx = -1;
		for(auto c: coins){
			if(c<=value){
				int v=runner(dp,coins,value-c);
				if(v!=-1){
					if(mx==-1) mx=v+1;
					else mx=min(mx,v+1);
				}
			}
			else break;
		}
		return dp[value]=mx; 
	}
};

int main(){
	vector<int> coins = {3,4};
	Solution sln;
	cout<<sln.coinChange(coins,5)<<endl;
	return 0;
}