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
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  	int n = nums.size();
  	int count = 0;
    int product = 1;
    int left = 0;
    if(k<=1) return 0;
    for(int i=0; i<n; i++) {
      product = product * nums[i];
      while(product >= k) {
        product = product / nums[left];
        left++;
      }
      count += (i - left + 1);
    }
    return count;
  }
};

int main() {
	vector<int> a = {10,5,2,6};
  vector<int> b = {20,20,30};
	Solution sln;
	// int x = sln.maxProduct(a);
	// int y = sln.maxProduct(b);
	int z = sln.numSubarrayProductLessThanK(b, 10);
	cout << z << endl;
	return 0;
}