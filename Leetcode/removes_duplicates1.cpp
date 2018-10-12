#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
    	if(nums.size()==0)
    		return 0;
        int i=0;
        int j=1;
        while(j<nums.size()){
        	if(nums[i]==nums[j])
        		j++;
        	else
        		nums[++i] = nums[j++];
        }
        nums.erase(nums.begin()+i+1, nums.end());
        return nums.size();
    }
};

int main(){
	vector<int> v = {};
	Solution sln;
	int len = sln.removeDuplicates(v);
	cout<<sln.removeDuplicates(v)<<endl;
	return 0;
}