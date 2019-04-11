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
  vector<string> removeInvalidParentheses(string s) {
  	int left_c = 0, right_c = 0;
  	for(int i=0; i<s.length(); i++) {
  		if(s[i] == '(') left_c++;
  		else if(s[i] == ')') {
  			if(left_c <= 0) right_c++;
  			else left_c--; 
  		}
  	}
  	vector<string> res;
  	dfs(0,left_c,right_c,s,res);
  	return res;
  }
  void dfs(int start, int left_c, int right_c, string str, vector<string> &res) {
  	if(left_c == 0 && right_c == 0){
  		// cout << "came " << str << " " << is_valid(str) <<  endl;
  		if(is_valid(str)) res.pb(str);
  		return;	
  	}
  	for(int i=start; i<str.length(); i++) {
  		if(right_c == 0 && left_c > 0 && str[i]=='(') {
  			if(i == start || str[i] != str[i-1]) {
  				string to_send = str;
  				to_send.erase(i,1);
  				dfs(i, left_c-1, right_c, to_send, res);
  			}
  		}
  		else if(right_c > 0 && str[i] == ')') {
  			if(i == start || str[i] != str[i-1]) {
  				string to_send = str;
  				to_send.erase(i,1);
  				dfs(i, left_c, right_c-1, to_send, res);
  			}
  		}
  	}
  }
  int is_valid(string str) {
  	int count = 0;
  	for(auto s: str) {
  		if(s=='(') count++;
  		else if(s==')') count--;
  		if(count<0) return 0;
  	}
  	return count==0;
  }
};

int main() {
	Solution sln;
	vector<string> test = {"()())()", "(a)())()", ")(", "(", ""};
	for(auto t: test) {
		vector<string> curr = sln.removeInvalidParentheses(t);
		for(auto c: curr) cout << c << endl;
		cout << "##############################################################" << endl;	
	}
}