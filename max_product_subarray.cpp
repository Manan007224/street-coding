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
  int maxProduct(vector<int>& nums) {
  	int n = nums.size();
  	int prev_max = nums[0], prev_min = nums[0], curr_max = nums[0], curr_min = nums[0];
  	int res = curr_max;
  	for(int i=1; i<n; i++) {
  		curr_max = max({prev_max*nums[i], prev_min*nums[i], nums[i]});
  		curr_min = min({prev_max*nums[i], prev_min*nums[i], nums[i]});
  		res = max(res, curr_max);
  		prev_max = curr_max;
  		prev_min = curr_min; 
  	}
  	return res;    
  }
};

int main() {
	vector<int> a = {2,3,-2,4};
	vector<int> b = {-2,0,-1};
	vector<int> c = {-2,3,-6};
	Solution sln;
	// int x = sln.maxProduct(a);
	// int y = sln.maxProduct(b);
	int z = sln.maxProduct(c);
	cout << z << endl;
	return 0;
}