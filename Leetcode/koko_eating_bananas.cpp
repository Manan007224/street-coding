#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int n = piles.size();
    int hi = 1000000000, lo = 1;
    while(lo < hi) {
    	int mid = (hi + lo)/2;
    	int req_h = 0;
    	for(int i = 0; i < n; ++i) {
    		req_h += (piles[i] + mid - 1)/mid;
    	}
    	if(req_h <= H) hi = mid;
    	else lo = mid + 1;
    }
    return lo;
  }
};

int main() {
	vector<int> t1 = {3,6,7,11};
	Solution sln;
	cout << sln.minEatingSpeed(t1, 8) << endl;
	return 0;
}