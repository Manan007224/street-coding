#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;
typedef vector<string> lst_s;
typedef vector<char> lst_c;
typedef vector<bool> lst_b;

int jumps(int s, lst n, lst dp){
	if(s==n.size()-1)
		return 1;
	if(n[s]==0 || s>=n.size())
		return 0;
	if(dp[s]!=-1)
		return dp[s];
	int r=0;
	for(int k=1;k<=n[s];k++)
		if(jumps(s+k,n,dp)==1)
			r=1;
	return dp[s]=r;
}

class Solution {
public:
    bool canJump(lst& nums) {
    	lst dp(nums.size(),-1);
        return (jumps(0,nums,dp)==1);
    }
};

int main(){
	lst nums={8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,
			2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,
			1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
	Solution sln;
	if(sln.canJump(nums))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
