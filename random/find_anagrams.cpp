#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ll=s.length();
        int lp=p.length();
        lst og(256,0);
        lst ag(256,0);
        lst ans;
        for(int k=0;k<lp;k++) og[int(p[k])]++;
        for(int i=0;i<ll-(lp-1);i++){
        	for(int j=i;j<i+lp;j++){
        		ag[int(s[j])]++;
        	}
        	bool flag=true;
        	for(int t=0;t<256;t++){
        		if(ag[t]!=og[t]){
        			flag=false;
        			break;
        		}
        	}
        	if(flag) ans.push_back(i);
        	for(int t=0;t<256;t++) ag[t]=0;
        }
		return ans;    
    }
};

int main(){
	string s="abab";
	string p="";
	Solution sln;
	lst ans;
	ans=sln.findAnagrams(s,p);
	for(auto a:ans) cout<<a<<endl;
	return 0;
}
