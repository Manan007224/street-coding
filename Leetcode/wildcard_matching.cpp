#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
  bool isMatch(string s, string p) {
  	if(s.length()==0) return p.length()==0 || p=="*";
  	int a = s.length(), b = p.length();
  	vii dp(a+1,vi(b+1,-1));
  	dp[a][b]=1;
  	return go(s,p,0,0,dp);     
  }
  int go(string &s,string &p,int i,int j,vii &dp){
  	if(dp[i][j]!=-1) return dp[i][j];
  	bool res=0;
  	if(p[j]=='*'){
  		res |= go(s,p,i,j+1,dp);
  		res |= (i<s.length() && go(s,p,i+1,j,dp));
  	}
  	else if(p[j]=='?') res |= (i<s.length() && go(s,p,i+1,j+1,dp));
  	else if(p[j]==s[i]) res |= (i<s.length() && go(s,p,i+1,j+1,dp));
  	return dp[i][j]=res;
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
	Solution sln;
	cout<<sln.isMatch(s,p)<<endl;
	cout<<sln.isMatch(s1,p1)<<endl;
	cout<<sln.isMatch(s2,p2)<<endl;
	cout<<sln.isMatch(s3,p3)<<endl;
	cout<<sln.isMatch(s4,p4)<<endl;
	return 0;
}