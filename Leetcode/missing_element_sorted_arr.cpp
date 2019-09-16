#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingElement(vector<int>& nums, int k) {
  	int n = nums.size();
  	vector<int> M(n);
  	M[0] = 0;
  	for(int i=1; i<n; i++) M[i] = nums[i]-nums[i-1]-1+M[i-1];
  	int j = 0;
  	if(k > M[n-1]) return nums[n-1]+k-M[n-1];
  	while(M[j] < k) j++;
  	return nums[j-1]+k-M[j-1]; 	
  }
};

int main() {
	vector<int> v = {4,7,10,12};
	Solution sln;
	cout << sln.missingElement(v, 6) << endl;
	return 0;
}