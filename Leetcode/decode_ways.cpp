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
    if(n==0 ||s[0]=='0') return 0;
  	if(n==1) return 1;
  	vector<int> dp(n, 0);
   	s[0] == '0' ? dp[0] = 0 : dp[0] = 1;
   	s[1]=='0' ? dp[1] = 0 : dp[1] = 1;
  	if(s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
  		dp[1]++;
  	for(int i=2; i<n; i++) {
  		if(s[i] != '0') 
  			dp[i] = dp[i-1];
  		if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
  			dp[i] += dp[i-2];
  	}
  	return dp[n-1];
  }
};
int main() {
	string s = "123";
	string s1 = "226";
	Solution sln;
	cout << sln.numDecodings(s) << endl;
	cout << sln.numDecodings(s1) << endl;
	return 1;
}