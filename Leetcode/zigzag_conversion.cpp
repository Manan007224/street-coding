#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	int k{numRows}, ls{0}, other{0}, cp{0};
    	bool mj=true;
  		vector<string> vs(k);
  		string ans="";
  		if(k==1) return s;
  		if(k==2){
  			for(int i=0;i<s.size();i++) vs[i%2].push_back(s[i]);
  		} 
  		else{
  			for(int i=0; i<s.length(); i++){
	  			if(other==(k-2))
					other=0, cp=0, ls=i, mj=1;	
				else if(cp==k)
					other=0, cp=0, mj=0;
				if(mj){
					vs[i-ls]+=s[i];
					cp++;
				}
				else{
					vs[k-2-other]+=s[i];
					other++;
				}
  			}
	  		
  		}
	  	for(auto v:vs) ans+=v;
	  	return ans;     	
    }
};


int main(){
	string test="PAYPALISHIRING";
	Solution sln;
	cout<<sln.convert(test,4)<<endl;
	return 0;
}