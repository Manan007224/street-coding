#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	int ll=nums.size();
    	if(ll==0) return;
        for(int i=0;i<ll-1;i++){
        	if(i%2==0){
        		if(nums[i]>nums[i+1]) swap(nums[i],nums[i+1]);
        	}
        	else{
        		if(nums[i]<=nums[i+1]) swap(nums[i],nums[i+1]);
        	}
        }
    }

};

int main(){
	vector<int> t1={1, 5, 1, 1, 6, 4};
	Solution sln;
	sln.wiggleSort(t1);
	for(auto t:t1) cout<<t<<endl;
	return 0;
}