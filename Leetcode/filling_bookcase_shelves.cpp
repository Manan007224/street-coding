#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
  	int n = books.size();
  	vector<int> dp(n+1, INT_MAX);
  	dp[0] = 0;
  	for(int i=1; i<=n; i++) {
  		int mh = 0, mw = shelf_width;
  		for(int j=i-1; j>=0; j--) {
  			if(mw - books[j][0] < 0) break;
  			mw -= books[j][0];
  			mh = max(mh, books[j][1]);
  			dp[i] = min(dp[i], dp[j] + mh);
  		}
  	}
  	return dp[n];   
  }
};

int main() {
	Solution sln;
	vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
	cout << sln.minHeightShelves(books, 4) << endl;
	return 0;
}