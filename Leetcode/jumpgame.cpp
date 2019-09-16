#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int lri = nums.size() - 1;
    for(int i = nums.size() - 2; i >= 0; i--) {
      if(nums[i] + i >= lri) lri = i; 
    }
    return lri == 0;
  }
};

int main() {
	vector<int> arr = {2,3,1,1,4};
	vector<int> arr1 = {3,2,1,0,4};
	Solution sln;
	cout << sln.canJump(arr) << endl;
	cout << sln.canJump(arr1) << endl;
	return 0;
}