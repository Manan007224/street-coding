#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> M = {{'-',1},{'+',1},{'/',2},{'*',2}};
bool h(char a, char b) {return M[a] >= M[b];}

int main() {
	int n; cin >> n;
	while(n--) {
		string s = "", ix = "", px = "";
		cin.ignore();
		while(getline(cin, s)) {
			if(s=="") break;
			ix += s;
		}
		stack<int> st;
		for(auto c: ix) {
			if(isdigit(c))
				px += c;
			else if(c == '(') 
				st.push(c);
			else if(c == ')') {
				while(!st.empty() && st.top() != '('){
					px += st.top();
					st.pop();
				}
			}
			else {
				while(!st.empty() && h(st.top(),c) && st.top() != '('){
					px += st.top();
					st.pop();
				}
				st.push(c);
			}
		}
		while(!st.empty() && st.top()!= '('){
			px += st.top();
			st.pop();
		}
		cout << px << endl;
	}
	return 0;
}