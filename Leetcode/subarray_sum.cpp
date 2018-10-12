#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int front=0;
		int back=0;
		int sum = nums[0];
		int mx = 0;
		if(nums.size()==1 && sum>k)
			return 0;
		int sz = nums.size();
		while(back<sz && front<sz){
			if(sum==k){
				mx++;
				sum=sum+nums[back+1]-nums[front];
				front++;
				back++;
			}
			else if(sum<k && back!=sz-1){
				back++;
				sum+=nums[back];
			}
			else{
				sum=sum-nums[front];
				front++;	
			}
		}
		return mx;
	}
};

int main(){
	vector<int> v = {100,1,2,3,4};
	Solution sln;
	cout<<sln.subarraySum(v,6)<<endl;
	return 0;
}