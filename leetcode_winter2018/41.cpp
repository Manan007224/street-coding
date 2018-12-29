#include <bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ll=nums.size();
        int hi=*max_element(nums.begin(),nums.end());
        int sp{INF}, lo{};
        for(int i=0;i<ll;i++){
        	if(nums[i]>0 && nums[i]<smallest_pos) sp=nums[i];
        }
        lo=sp;
        int n=hi-low;
        int gap_sum=(n*(n+1))/2;
        for(int i=0;i<ll;i++){
        	if(nums[i]>0 && nums[i]<=hi && nums[i]>=lo)
        		gap_sum-=nums[i];
        }
    }
};

int main(){
	return 0;
}