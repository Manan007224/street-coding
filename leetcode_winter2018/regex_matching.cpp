#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool recur(string s, string p){
		bool ans=false;
		int ls=s.size();
		int lp=p.size();
		if(lp==0) return ls==0;
		if(lp>=2 && p[1]=='*'){
			string st=s; 
			string pt=p;	
			if(s[0]==p[0] || p[0]=='.') 
				ans = (ls>0) && (ans || recur(st.substr(1),p));
			ans = ans || recur(s,pt.substr(2));	
		}
		else{
			if(ls>0 &&(s[0]==p[0] || p[0]=='.'))
				ans = ans || recur(s.substr(1),p.substr(1));
		}
		return ans;		
	}
    bool isMatch(string s, string p) {
        return recur(s,p);
    }
};

int main(){
	string s="mississippi";
	string p="mis*is*p*.";
	Solution sln;
	if(sln.isMatch(s,p)) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	return 0;
}