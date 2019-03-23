#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> M = {{'-',1},{'+',1},{'/',2},{'*',2}};
bool h(char a, char b) {return M[a] >= M[b];}

class Solution {
public:
  int calculate(string s) {
  	if(s=="") return 0;
    stack<int> st, st1;
    string px = "";
    for(auto c: s) {
    	if(s!="") {
    		if(isdigit(c))
				px += c;
				else if(c == '(') 
					st.push(c);
				else if(c == ')') {
					while(!st.empty() && st.top() != '('){
						px += st.top();
						st.pop();
					}
					if(!st.empty()&&st.top()=='(') st.pop();
				}
				else {
					while(!st.empty() && st.top() != '(' && h(st.top(),c)){
						px += st.top();
						st.pop();
					}
					st.push(c);
				}
    	}
		}
		while(!st.empty() && st.top()!= '('){
			px += st.top();
			st.pop();
		}
		if(!st.empty()&&st.top()=='(') st.pop();
    for(auto p:px){
    	if(p=='/'||p=='*'||p=='-'||p=='+') {
  			int x = st1.top(); st1.pop();
  			int y = st1.top(); st1.pop();
  			int z;
  			if(p=='/') z=y/x;
  			else if(p=='*') z=y*x;
  			else if(p=='+') z=y+x;
  			else z=y-x;
  			st1.push(z);
  		}
  		else st1.push(int(p)-48);
    } 
    return st1.top();
  }
};

int main() {
	string t = "(1+(4+5+2)-3)+(6+8)";
	string t2 = "1 + 1";
	string t3 = "2-1+2";
	string t1 = "(4+(13/5))";
	Solution sln;
	cout << sln.calculate(t) << endl;
	cout << sln.calculate(t2) << endl;
	cout << sln.calculate(t3) << endl;
	return 0;
}