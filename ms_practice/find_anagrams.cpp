#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ll = s.length();
        int lp = p.length();
        vector<int> og(256,0);
        vector<int> anagrams(256,0);
        vector<int> ans;
        for(int k=0;k<lp;k++) og[int(p[k])]++;
        for(int i=0;i<ll-(lp-1);i++){
        	for(int j=i;j<i+lp;j++){
        		anagrams[int(s[j])]++;
        	}
        	bool flag=true;
        	for(int t=0;t<256;t++){
        		if(anagrams[t]!=og[t]){
        			flag=false;
        			break;
        		}
        	}
        	if(flag==true) ans.push_back(i);
        	for(int t=0;t<256;t++) anagrams[t]=0;
        }
		return ans;    
    }
};

int main(){
	string s = "abab";
	string p = "";
	Solution sln;
	vector<int> ans;
	ans = sln.findAnagrams(s,p);
	for(auto a : ans) cout<<a<<endl;
	return 0;
}