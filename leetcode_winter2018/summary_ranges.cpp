#include <bits/stdc++.h>
using namespace std;
typedef unordered_set<int> usi;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		if(nums.size() == 0) return res;
		int first {nums[0]}, last {nums[0]};
		for(int i=1; i<nums.size(); i++) {
			if(last + 1 != nums[i]) {
				if(first == last) res.push_back(to_string(first));
				else res.push_back((to_string(first) + "->" + to_string(last)));
				first = last = nums[i];
			}
			else last = nums[i];
		}
		if(first == last) res.push_back(to_string(first));
		else res.push_back((to_string(first) + "->" + to_string(last)));
		return res;       
    }
};

int main(){
	Solution sln;
	vector<int> nums = {0,1,2,4,5,7};
	vector<string> res = sln.summaryRanges(nums);
	for(auto r:res) cout<<r<<endl;
	return 0;
}