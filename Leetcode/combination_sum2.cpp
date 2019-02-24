#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> res;
    	vi curr;
    	if(candidates.size() == 0 || target == 0){
    		return res; 
    	}
    	sort(candidates.begin(), candidates.end());
        bool temp = go(target, candidates, res, curr, 0);
        return res;
    }

    bool go(int t, vi nums, vvi& res, vi& curr, int x) {
    	if(t < 0) return 0;
    	if(t == 0) return 1;
    	for(int i=x; i<nums.size(); i++) {
    		if(i > x && nums[i] == nums[i-1])
    			continue;
    		curr.push_back(nums[i]);
    		bool w = go(t-nums[i], nums, res, curr, i+1);
    		if(w) res.push_back(curr);
    		curr.pop_back();
    	}	
    	return 0;
    }
};

int main() {
	Solution sln;
	vi T = {1,1,2,5};
	vi T1 = {2,3,5};
	vvi res = sln.combinationSum(T, 8);
	for(auto rr: res) {
		for(auto r : rr) cout << r << " ";
		cout << endl;
	}
	return 0;
}
