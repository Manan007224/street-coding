#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
  		int ll=s.length();
  		if(ll==0) return 0;
  		int c{0}, lidx{0}, res{0};
  		// for left hand side
  		for(int i=0;i<ll;i++){
  			if(s[i]=='(') c++;
  			else c--;
  			if(c==0)
  				res=max(res,(i-lidx+1));
  			if(c<0){
  				lidx=i+1;
  				c=0;
  			}
  		}
  		c=0, lidx=ll-1;
  		// do the same from right side
  		for(int i=ll-1;i>=0;i--){
  			if(s[i]==')') c++;
  			else c--;
  			if(c==0)
  				res=max(res,(lidx-i+1));
  			if(c<0){
  				lidx=i-1;
  				c=0;
  			}
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