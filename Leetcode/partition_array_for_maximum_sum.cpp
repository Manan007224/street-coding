#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int K) {
  	int n = A.size();
  	vector<int> dp(n+1, 0);
  	for(int i = 1; i <= n; i++) {
  		int j = i-1;
  		int mx = 0;
  		while(j >= 0 && j >= i-K) {
  			mx = max(mx, A[j]);
  			dp[i] = max(dp[i], dp[j] + (i-j)*mx);
  			j--;
  		}
  	}
  	return dp[n];    
  }
};

int main() {
	vector<int> arr = {1,15,17,9};
	Solution sln;
	cout << sln.maxSumAfterPartitioning(arr, 3) << endl;
}