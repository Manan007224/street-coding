#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int pivot(vector<int>& nums){
		int l=0;
		int r=nums.size()-1;
		while(l<r){
			int m=(l+r)/2;
			if(nums[m]<nums[m-1]) return m-1;
			if(nums[m]>nums[m+1]) return m;
			nums[m]>nums[r] ? l=m+1:r=m-1;
		}
		return -1;
	}
    int search_complex(vector<int>& nums, int target){
    	if(nums.size()==0) return -1;
       	int pt=pivot(nums);
       	int cc=nums.size()-1;
       	int l,r;
       	if(pt==-1) l=0, r=cc;
       	else if(target==nums[pt]) return pt;
       	else{
       		if(nums[0]>target) l=pt+1, r=cc;
       		else l=0, r=pt-1;
       	}
       	if(l==r) return nums[l]==target ? l:-1;
       	while(l<=r){
       		int m=(l+r)/2;
       		if(nums[m]==target) return m;
       		if(nums[m]<target) l=m+1;
       		else r=m-1;
       	}
       	return -1; 
    }

    int search(vector<int>& nums, int target){
        int sz=nums.size();
        if(sz==0) return -1;
        int l=0;
        int r=sz-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target==nums[m]) return m;
            if(nums[l]<nums[m]){
                if(target>=nums[l] && target<nums[m]) r=m-1;
                else l=m+1;
            }
            else{
                if(target>nums[m] && target<=nums[r]) l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};

int main(){
	vector<int> v={4,5,6,7,0,1,2};
	Solution sln;
	int ans=sln.search(v,1);
	cout<<ans<<endl;
	return 0;
}