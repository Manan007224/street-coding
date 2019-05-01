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
  int numDecodings(string s) {
    int n = s.length();
    static const int MOD = 1000000007;
    vector<i64> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '*' ? 9 : (s[0] != '0' ? dp[0] : 0);
    for(int i=1; i<n; i++) {
      if(s[i] == '*') {
        dp[i+1] = dp[i]*9;
        if(s[i-1] == '1') dp[i+1] = (dp[i+1] +  dp[i-1] * 9) % MOD;
        else if(s[i-1] == '2') dp[i+1] =  (dp[i+1] + dp[i-1] * 6) % MOD;
        else if(s[i-1] == '*') dp[i+1] =  (dp[i+1] + dp[i-1] * 15) % MOD;
      }
      else {
        if(s[i] != '0') dp[i+1] = dp[i];
        if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) dp[i+1] =  (dp[i+1] + dp[i-1]) % MOD;
        else if(s[i-1] == '*') (s[i] <= '6') ? dp[i+1] = (dp[i+1] + 2*dp[i-1]) % MOD : (dp[i+1] += dp[i-1]) % MOD; 
      }
    }
    return dp[n];  	
  }
};

int main() {
	Solution sln;
  while(true) {
    string s; cin >> s;
    if(s == "") break;
    cout << sln.numDecodings(s) << endl;
  }
	// cout << sln.numDecodings(s) << endl;
	return 1;
}