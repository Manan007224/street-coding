#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool match(string &c) {
	stack<int> brackets;
	for(int i=0;i<c.length(); i++) {
		if(c[i] == '(') brackets.push(c[i]);
		if(c[i] == ')') {
			char tp = brackets.top(); 
			brackets.pop();
			if(tp != '(') return false;
		}
	}
	if(brackets.size()==0) return true;
	else return false;
}

// Using BFS

int rem_p(string &st) {
	int og = st.length();
	if(st.empty()) return 0;
	queue<string> q;
	q.push(st);
	while(!q.empty()) {
		string str = q.front(); 
		q.pop();
		cout << "String = " << str << endl;
		cout << match(str) << endl;
		if(match(str)) 
			return og-str.length();
		for(int i=0;i<str.length();i++) {
			if(str[i] != '(' || str[i] != ')')
				continue;
			string tp = str.substr(0,i) + str.substr(i+1);
			cout << tp << endl;
			q.push(tp);
		}
	}
}

int main() {
	string test = "(()))(";
	cout << rem_p(test) << endl;
}