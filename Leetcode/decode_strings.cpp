#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  string decodeString(string s) {
 		stack<int> nums;
 		stack<string> strs;
		int x = 0;
		string curr = "";
		for(int i=0; i<s.length(); i++) {
			if(isdigit(s[i]))
				x = (x*10  + (s[i]-'0') % 48);
			else if(s[i] == '[') {
				nums.push(x);
				strs.push(curr);
				x = 0, curr = "";
			}
			else if(s[i] == ']') {
				string now = strs.top();
				int ff = nums.top();
				for(int j=0; j<ff; j++) now += (curr);
				curr = now;
				nums.pop();
				strs.pop();
			}
			else curr += s[i];
		}
		return curr;	     
  }
};

int main() {
	string a = "3[a2[c]]";
	string b = "3[a]2[bc]";
	string c = "2[abc]3[cd]ef";
	string d = "10[a]";
	Solution sln;
	cout << sln.decodeString(b) << endl;
	cout << sln.decodeString(d) << endl;
	return 0;
}