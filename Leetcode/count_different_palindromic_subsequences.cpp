#include <bits/stdc++.h>
using namespace std;

const int L = 1e3, M = 1e9 + 7;
long long dp[L][L];

class Solution {
public:
  int countPalindromicSubsequences(string S) {
  	memset(dp, 0, sizeof(dp));
    int n = S.length();
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int k=1; k<n; k++) {
      for(int i=0; i<n-k; i++) {
        int j = i+k;
        if(S[i]!=S[j]) {
          dp[i][j] = dp[i+1][j] + dp[i][j-1] - (dp[i+1][j-1]); 
        }
        else {
          dp[i][j] = 2*dp[i+1][j-1];
          int start = i+1, end = j-1;
          char check = S[j];

          // For checking duplicates
          while(start<=end && S[start]!=check) start++;
          while(start<=end && S[end]!=check) end--;

          // no repeating charachter b***b where none one of the *'s are b 
          if(start > end) {
            dp[i][j] += 2;
          }

          // atleast two repeating charachters b**b ..b**b 
          else if(start < end) {
            dp[i][j] -= dp[start+1][end-1];
          }

          // just one repeating charachter b**b**b
          else {
            dp[i][j] += 1;
          }
        }
        dp[i][j] = (dp[i][j] + M) % M;
      }
    }
    return static_cast<int>(dp[0][n-1]);
  }
};

int main() {
  vector<string> test = {"bccb", "aacaa", "abcdaefga", "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba","afga", ""};
  Solution sln;
  for(auto t : test) cout << t << " : " << sln.countPalindromicSubsequences(t) << endl;
	return 0;
}