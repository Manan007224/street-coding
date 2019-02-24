#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ll=nums.size();
        if(ll==0) return 0;
        if(nums[0]==s) return 1;
        int i{0}, j{1}, res{INF}, sum{nums[0]+nums[1]};
        while(i<ll && j<ll){
        	if(i<=j){
	        	if(sum>=s){
	        		res=min(res,j-i+1);
	        		sum-=nums[i++];
	        	}
	        	else
	        		sum+=nums[++j];
	        }
        }
        return (res==INF) ? 0 : res;
    }
};

int main(){
	vector<int> test={1,2,3,4,5};
	Solution sln;
	cout<<sln.minSubArrayLen(11,test)<<endl;
	return 0;
}