#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef stringstream ss;

class Solution {
public:
	string simplifypath(string path){
		if(path == "") return "/";
		ss input(path);
		vs files;
		string f, res;
		stack<string> st;
		while(getline(input, f, '/')) {
			if(f=="." || f=="") continue;
			if(f=="..") {
				if(!st.empty()) st.pop();
			}
			else st.push(f);
		}
		while(!st.empty()) {
			res = "/" + st.top() + res;
			st.pop();
		}
		return res == "" ? "/" : res;
	}
};

int main(){
	Solution sln;
	cout<<sln.simplifypath("/a//b////.crc/d//././/..")<<endl;
	return 0;
}