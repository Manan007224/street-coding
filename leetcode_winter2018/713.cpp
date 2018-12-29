// https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start{0},x{0}, pr{1};
        if(nums.size()<=0) return 0;
        for(int i=0;i<nums.size();i++){
        	pr=pr*nums[i];
        	while(pr>=k) pr=pr/nums[start++];
        	x=x+(i-start)+1;
        }
        return x;
    }
};

int main(){
	vector<int> v = {10,5,2,6};
	Solution sln;
	cout<<sln.numSubarrayProductLessThanK(v,100)<<endl;
	return 0;
}