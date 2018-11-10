#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	bool dot=false;
    	stack<string> st;
    	int k=-1;
    	while(++k<path.size()){
    		if(path[k]=='/'){
    			dot=false;
    			continue;
    		}
    		if(path[k]=='.'&&(dot) && !isalpha(path[k+1])){
    			if(!st.empty()) st.pop();
    			dot=true;
    		}
    		else if(path[k]=='.'&&(!dot) && !isalpha(path[k+1])) dot=true;
    		else{
    			int pr=k;
    			while(path[k]!='/'){
    				k++;
    				if(path.size()<k) break;
    			}
				st.push(path.substr(pr,k-pr));
    		}
    	}
    	string ans="";
    	while(!st.empty()){
    		ans="/"+st.top()+ans;
    		st.pop();
    	}
    	return (ans=="")?"/":ans;
    }
};

int main(){
	string str="/home/foo/.bashrc";
	int k=1;
	Solution sln;
	string ans=sln.simplifyPath(str);
	cout<<ans<<endl;
	return 0;
}