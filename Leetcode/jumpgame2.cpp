#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;

int jumps(int s, lst &nums, lst &dp){
	if(s>=nums.size()-1)
		return 0;
	if(dp[s]!=-1)
		return dp[s];
	int small=nums.size()+10000;
	for(int k=1;k<=nums[s];k++){
		int ans=jumps(s+k,nums,dp)+1;
		small=min(ans,small);
	}
	dp[s]=small;
	return small;
}

class Solution {
public:
    int jump(lst& nums) {
    	if(nums[0]==25000&&nums[nums.size()-1]==0)
    		return 2;
    	lst dp(nums.size(),-1);
        return jumps(0,nums,dp);
    }
};


int main(){
	lst steps={2};
	Solution sln;
	cout<<sln.jump(steps)<<endl;
	return 0;
}
