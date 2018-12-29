#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int ll=nums.size();
    	if(ll==0 || ll==1) return;
		int r{0}, x{0}, b{ll-1};
    	while(r<b && x<=b){
    		if(nums[x]==0){
    			swap(nums[x++],nums[r++]);
    		}
    		else if(nums[x]==1) ++x;
    		else if(nums[x]==2){
    			swap(nums[x],nums[b--]);
    		}
    	}
    	return;	
    }
};

int main(){
	vector<int> t1={2,0,2,1,0,1};
	Solution sln;
	sln.sortColors(t1);
	for(int i=0;i<t1.size();i++) cout<<t1[i]<<endl;
	return 0;
}