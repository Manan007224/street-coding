#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
  	int n = nums.size(), jp = 0, pos = 0;
  	while(pos < n - 1) {
  		int next_pos = pos;
  		jp++;
  		for(int i = 0; i <= nums[pos]; i++) {
  			int tp = i + pos;
  			if(tp >= n - 1) return jp;
  			next_pos = max(next_pos, nums[tp] + tp);
  		}
  		pos = next_pos;
  	}
  	return jp;
  }
};


int main() {
	vector<int> p = {2, 3, 1, 1, 4};
	Solution sln;
	cout << sln.jump(p) << endl;
	return 0;
}
