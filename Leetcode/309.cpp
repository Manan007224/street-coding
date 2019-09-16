#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
  	int n = prices.size();
    if(n==0 || n==1) return 0;
  	vector<int> b(n), s(n);
  	b[0] = -(prices[0]);
  	for(int i=1; i<n; i++) {
  		b[i] = b[i-1];
  		if(i-2 >= 0) b[i] = max(s[i-2]-prices[i], b[i]);
  		s[i] = max(s[i-1], b[i-1]+prices[i]);
  	}
  	return s[n-1];
  }
};


int main() {
	vector<int> t = {1,2,3,0};
	Solution sln;
	cout << sln.maxProfit(t) << endl;
	return 0;
}