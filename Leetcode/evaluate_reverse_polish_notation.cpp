#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
  	if(tokens.length()==0) return 0;
  	stack<int> st;
  	for(auto t: tokens) {
  		if(t=="/"||t=="*"||t=="-"||t=="+") {
  			int x = st.top(); st.pop();
  			int y = st.top(); st.pop();
  			int z;
  			if(t=="/") z=y/x;
  			else if(t=="*") z=y*x;
  			else if(t=="+") z=y+x;
  			else z=y-x;
  			st.push(z);
  		}
  		else st.push(stoi(t));
  	}
  	return st.top();
  }
};

int main(){
	vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	vector<string> tokens1 = {"4", "13", "5", "/", "+"};
	Solution sln;
	cout << sln.evalRPN(tokens1) << endl;
	return 0;
}