#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check_valid(char op, char cl) {
	if(op == '{' && cl == '}') return true;
	else if(op == '(' && cl == ')') return true;
	else if(op == '[' && cl == ']') return true;
	else return false;
}

bool check_paranthesis_matching(string &check) {
	stack<int> brackets;
	for(int i=0;i<check.length();i++) {
		if(check[i] == '{' || check[i] == '(' || check[i] == '[') 
			brackets.push(check[i]);
		if(check[i] == '}' || check[i] == ')' || check[i] == ']') {
			if(brackets.size() == 0) return false;
			else {
				char last = brackets.top();
				brackets.pop();
				char current = check[i];
				if(check_valid(last,current) == false) return false; 
			}
		}
	}
	if(brackets.size() == 0) return true;
	else return false;
}

int main() {
	string check; cin>>check;
	if(check_paranthesis_matching(check))
		cout << "Valid Format" << endl;
	else 
		cout << "Invalid Format" << endl;
	return 0;
}