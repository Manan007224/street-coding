#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

class Solution {
public:
  bool isMatch(string s, string p) {
  	if(s.length()==0) return p.length()==0 || p=="*";
  	int a = s.length(), b = p.length();
    vvb dp(a+1,vb(b+1,0));
  	dp[a][b]=1;
    for(int i=s.length(); i>=0; i--) {
      for(int j=p.length()-1; j>=0; j--) {
        if(p[j]=='*') {
          if(i<s.length()) dp[i][j] = dp[i+1][j]; 
          dp[i][j] = dp[i][j] || dp[i][j+1];
        }
        else if(p[j]=='?' || p[j]==s[i]) {
          dp[i][j] = (i<s.length() && dp[i+1][j+1]);
        }
      }
    }
    return dp[0][0];    
  }
};

int main() {
	string s = "abceb";
	string p = "*a*b";
	string s1 = "cb";
	string p1 = "?a";
	string s2 = "aa";
	string p2 = "*a";
	string s3 = "acbcb";
	string p3 = "a*c?b";
	string s4 = "d";
	string p4 = "";
  string ts = "abc";
  string tp = "a*";
	Solution sln;
	cout<<sln.isMatch(s,p)<<endl;
	cout<<sln.isMatch(s1,p1)<<endl;
	cout<<sln.isMatch(s2,p2)<<endl;
	cout<<sln.isMatch(s3,p3)<<endl;
	cout<<sln.isMatch(s4,p4)<<endl;
  cout << sln.isMatch(ts,tp) << endl;
	return 0;
}