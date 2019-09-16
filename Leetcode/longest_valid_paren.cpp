#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
  		int n = s.length();
  		if(n==0) return 0;
  		int c = 0, lidx = 0, res = 0;
  		for(int i=0; i<n; i++){
        s[i] == '(' c++ ? c--;
  			if(c==0) res=max(res,(i-lidx+1));
  			if(c<0) lidx=i+1, c=0;
  		}
  		c=0, lidx=ll-1;
  		for(int i=n-1; i>=0; i--){
  			s[i] == ')' c++ ? c--;
  			if(c==0) res=max(res,(lidx-i+1));
  			if(c<0) lidx=i-1, c=0;
  		}
  		return res;    
    }
};

int main(){
	string s=")(()())())";
	string s1="(()()";
	string s2="(()())())()()()()()";
	Solution sln;
	cout<<sln.longestValidParentheses(s1)<<endl;
	cout<<sln.longestValidParentheses(s)<<endl;
	cout<<sln.longestValidParentheses(s2)<<endl;
	return 0;
}