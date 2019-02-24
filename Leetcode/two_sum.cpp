#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int,int> record;
    	vi ans;
    	if(nums.size() == 0 || nums.size() == 1) return ans;
        for(int i=0; i<nums.size(); i++) {
        	if(record.find(target-nums[i]) != record.end()) {
        		ans.push_back(record[target-nums[i]]);
        		ans.push_back(i);
        		return ans; 
        	}
        	record.insert({nums[i], i});
        }
    }
};

int main() {
	vector<int> T = {2,7,11,15};
	Solution sln;
	auto res = sln.twoSum(T,9);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}