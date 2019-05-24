#include <bits/stdc++.h>
using namespace std;

const int L = 1e3, M = 1e9 + 7;
long long dp[L][L][4];
char c[] = {'a','b','c','d'};

class Solution {
public:
  int countPalindromicSubsequences(string S) {
  	int n = S.length();
  	memset(dp, 0, sizeof(dp));
  	long long res = n + 1;
  	for(int i = 0; i < n; i++) {
  		dp[i][i][S[i]-'a'] = 1;
  	}
  	for(int l = 2; l <= n; l++) {
  		for(int i = 0; i <= n - l + 1; i++) {
  			int j = i + l - 1;
  			for(int k = 0; k < 4; k++) {
  				if(S[i] == S[j] == c[k]) {
  					for(int m = 0; m < 4; m++) {
  						dp[i][j][k] += dp[i][j][m];
  						dp[i][j][k] = dp[i][j][k] % M; 
  					}
  				}
  				else if(S[i] != c[k]) dp[i][j][k] = dp[i+1][j][k];
  				else dp[i][j][k] = dp[i][j-1][k];
  			}
  		}
  	}
  }
};

int main() {
	return 0;
}