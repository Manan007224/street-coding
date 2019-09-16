#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
  	int n = num.length(), i = 1;
    stack<char> st;
    st.push(num[0]);
    for(; i<n; i++) {
    	if(!k) break;
    	while(!st.empty() && st.top() > num[i] && k) {
    		st.pop(); 
    		k--;
    	}
    	st.push(num[i]);
    }
    for(; i<n; i++) st.push(num[i]);
    while(k &&) 
    string res = "";
    while(!st.empty()) {
    	res += st.top();
    	st.pop(); 
    }
    reverse(res.begin(), res.end());
    int cnt = 0;
    while(res[cnt++] != '0' && cnt < res.length());
    return cnt != res.length() ? res.substr(cnt) : res;
  }
};

int main() {
	Solution sln;
	cout << sln.removeKdigits("1432219", 3) << endl;
	cout << sln.removeKdigits("10200", 1) << endl;
	return 0;
}