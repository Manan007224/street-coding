#include <bits/stdc++.h>
using namespace std;

int subs(vector<int> v){
	vector<int> dp(v.size());
	dp[0]=v[0];
	for(int k=1;k<v.size();k++){
		dp[k] = max(dp[k-1]+v[k], v[k]);	
	}
	return *max_element(dp.begin(),dp.end());	
}

int main(){
	vector<int> v = {1,-3,2,1,-1};
	cout<<subs(v)<<endl;
	return 0;
}
