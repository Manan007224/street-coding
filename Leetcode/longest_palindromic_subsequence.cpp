#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

class Solution {
public:
  int longestPalindromeSubseq(string s) {
  	memset(dp, 0, sizeof(dp));
  	int n = s.length();
    for(int i=0; i < n; i++) dp[i][i] = 1;
    for(int i=0; i < n-1; i++) dp[i][i+1] = (s[i]==s[i+1]) ? 2 : 1;
    for(int k = 3; k <= n; k++) {
    	for(int i = 0; i < n - k + 1; i++) {
    		int j = i + k - 1;
    		if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
    		else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    	}
    }
    return dp[0][n-1];
  }
};

int main() {
	string s = "agbdga";
	Solution sln;
	cout << sln.longestPalindromeSubseq(s) << endl;
	return 0;
}