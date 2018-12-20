#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int find_pivot(vector<int>& nums){
		int left = 0;
		int right = nums.size()-1;
		while(left<right){
			int mid = (left+right)/2;
			if(nums[mid]>nums[mid+1])
				return mid;
			if(nums[mid]<nums[mid-1])
				return mid-1;
			nums[mid]<nums[left] ? right=mid-1 : left=mid+1;
		}
		return -1;
	}

    int findMin(vector<int>& nums) {
  		if(nums.size()==0) return 0;
  		int pivot = find_pivot(nums);
  		if(pivot==-1)
  			return nums[0];
  		if(pivot+1>=nums.size())
  			return nums[0];
  		else return nums[pivot+1];
    }
};

int main(){
	vector<int> test={3,4,5,6,7,1,2};
	vector<int> test1={4,5,6,7,0,1,2};
	vector<int> test2={19,20,4,7,9,13};
	vector<int> test3={4,5,6,7,8};
	Solution sln;
	cout<<sln.findMin(test)<<endl;
	cout<<sln.findMin(test1)<<endl;
	cout<<sln.findMin(test2)<<endl;
	cout<<sln.findMin(test3)<<endl;
	return 0;
}