#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int>& weights, int D) {
    int n = weights.size();
    int hi = 0;
    int lo = *max_element(weights.cbegin(), weights.cend());
    for(auto w : weights) hi += w;
    while(lo <= hi) {
    	int mid = lo + (hi-lo)/2;
    	if(F(weights, D, mid) <= D) hi = mid-1;
    	else lo = mid+1;
    }
    return lo;  
  }
  int F(vector<int> &weights, int d, int l) {
  	int res = 0, cs = 0;
  	for(auto w: weights) {
  		if(cs + w > l) res++, cs = w;
  		cs += w;
  	}
  	return res;
  }
};

int main() {
	vector<int> w = {1,2,3,4,5,6,7,8,9,10};
	Solution sln;
	cout << sln.shipWithinDays(w, 5) << endl;
	return 0;
}