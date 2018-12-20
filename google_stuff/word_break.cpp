#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    	int ll=s.size();
    	if(ll==0 && s=="") return true;
    	if(ll==0) return false;
    	vector<int> dp(ll,0);
  		for(int i=0;i<ll;i++){
  			for(auto cr: wordDict){
  				int cc=cr.length();
  				if(i-cc>=0){
  					string check=s.substr((i-cc+1),cc);
  					if(check==cr && dp[i-cc]==1) dp[i]=1;
  				}
  				else if(i-cc==-1){
  					string check=s.substr((i-cc+1),cc);
  					if(check==cr) dp[i]=1;
  				}
  			}
  		}
  		return (dp[ll-1]==1)?true:false;      
    }
};

int main(){
	Solution sln;
	vector<string> test={"apple","pen"};
	vector<string> test1={"leet","code"};
	vector<string> test2={"cats", "dog", "sand", "and", "cat"};
	vector<string> test3={""};
	vector<string> test4={"a","b"};
	cout<<sln.wordBreak("applepenapple",test)<<endl;
	cout<<sln.wordBreak("leetcode",test1)<<endl;
	cout<<sln.wordBreak("catsandog",test2)<<endl;
	cout<<sln.wordBreak("baab",test4)<<endl;
	cout<<sln.wordBreak("",test3)<<endl;
	cout<<sln.wordBreak("leetcode",test3)<<endl;
	return 0;
}