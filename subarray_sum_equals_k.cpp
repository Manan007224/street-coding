#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> rec;
    int count = 0, sum = 0;
    rec[0]=1;
    for(int i=0; i<nums.size(); i++) {
    	sum += nums[i];
    	auto at_i = rec.find(sum - k);
    	if(at_i != rec.end()){
    		count += (at_i->second);
    	}
    	rec[sum]++;
    }
    return count; 
  }
};

int main() {
	vector<int> a = {3,4,7,2,-3,1,0,7};
	vector<int> b = {1,1,1};
	Solution sln;
	cout << sln.subarraySum(a, 7) << endl;
	return 0;
}