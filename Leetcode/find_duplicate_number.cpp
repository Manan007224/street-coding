#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
  	int n = nums.size();
  	for(auto x: nums) nums[x % n] += n;
  	for(int i=0; i<n; i++) if(nums[i]/n > 1) return i;    
  }
};

int main() {
	Solution sln;
	vector<int> nums = {1,3,4,2,5,3};
	cout << sln.findDuplicate(nums) << endl;
	return 0;
}