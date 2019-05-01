#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
  	vector<bool> v(nums.size(), 0);
  	int sum = 0;
  	for(auto n: nums) sum+=n;
  	if(sum % k != 0) return 0;
  	int target = (sum/k);
  	return go(nums, v, 0, target, target, k);      
  }

	bool go(vector<int> &arr, vector<bool> &v, int start, int curr_sum, int target, int k) {
		// cout << curr_sum << " " << k << endl;
		if(k==1)
			return 1;
		if(curr_sum < 0)
			return 0;
		if(curr_sum == 0)
			return go(arr, v, 0, target, target, k-1);
		for(int i=start; i<arr.size(); i++) {
			if(!v[i]) {
				v[i] = 1;
				bool works = go(arr, v, start+1, curr_sum-arr[i], target, k);
				if(works) return 1;
				v[i] = 0;
			}
		}
		return 0;
	}
};

int main() {
	vector<int> arr = {4,3,2,3,5,2,1};
	Solution sln;
	cout << sln.canPartitionKSubsets(arr, 4) << endl;
	return 0;
}