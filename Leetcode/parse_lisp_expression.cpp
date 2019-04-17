#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
	bool is_digit(char c) {return (c>='0' && c<='9');}

  int evaluate(string expression) {
  	unordered_map<string,int> sym_table;
  	return dfs(expression, sym_table);
  }

	string parse(string &s, int &start) {
	  int end = start+1, temp = start;
	  if (s[start] == '(') {
	  	int count = 1;
	    while (count != 0) {
	    	if(s[end]=='(') count++;
	    	else if(s[end]==')')count--;
	    	end++;
	    }
	  }
	  else {
	    while (end < s.size() && s[end] != ' ') end++;
	  }
	  start = end+1;
	  return s.substr(temp,end-temp);
	}

  int dfs(string expr, unordered_map<string,int> sym_table) {
  	if(is_digit(expr[0]))
  		return stoi(expr);
  	if(expr[0]!='(')
  		return sym_table[expr];
  	string s = expr.substr(1,expr.length()-2);
  	int idx = 0;
  	string curr = parse(s, idx);
  	if(curr=="let") {
  		while(true) {
  			string left = parse(s, idx);
  			if(idx > s.length())
  				return dfs(left, sym_table);
  			string right = parse(s, idx);
  			sym_table[left] = dfs(right,sym_table);
  		}
  	}
  	else if(curr=="add")
  		return dfs(parse(s, idx),sym_table) + dfs(parse(s, idx),sym_table);
  	else if(curr=="mult")
  		return dfs(parse(s, idx),sym_table) * dfs(parse(s, idx),sym_table);
  } 
};

int main() {
	string t = "(let x (add (add 2 3) 4) x)";
	string t1 = "(let x (add 2 3) x)";
	Solution sln;
	cout << sln.evaluate(t1) << endl;
	return 0;
}