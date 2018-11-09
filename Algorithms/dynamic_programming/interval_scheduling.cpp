#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
typedef vector<pair<int,int>> lst_p;
typedef vector<int> lst;

bool sortbydiff(pt &pt1, pt &pt2){return ((pt1.second)<(pt2.second));}

int cost(lst_p &jobs, lst &dp, int curr){
	if(curr==-1) return 0;
	if(dp[curr]!=-1) return dp[curr];
	int nc;
	pt fn=jobs[curr];
	bool flag=false;
	for(int k=jobs.size()-1;k>=0;k--){
		int cmp=jobs[k].second;
		if(cmp<=fn.first){
			nc=k;
			flag=true;
			break;
		}
	}
	int mx=(!flag)?(fn.second-fn.first):numeric_limits<int>::min();
	while(nc>=0){
		int wt=fn.second-fn.first;
		int ans=max((wt+cost(jobs,dp,nc)),cost(jobs,dp,curr-1));
		mx=max(ans,mx);
		nc--;
	}
	return dp[curr]=mx;
}

int main(){
	lst_p jobs={{0,6},{1,4},{3,5},{3,8},{4,7},{5,9},{6,10},{8,11}};
	lst dp(jobs.size(),-1);
	sort(jobs.begin(),jobs.end(),sortbydiff);
	int ans=cost(jobs,dp,jobs.size()-1);
	cout<<ans<<endl;
	return 0;
}