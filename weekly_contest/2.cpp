#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeDuplicates(string S) {
    if(S.length()==0) return "";
    string res = "";
    res += S[0];
    int n = S.length();
    for(int i = 1; i < n ; i++) {
      if(res[res.length()-1] == S[i]) {
        res.pop_back();
      }
      else res += S[i];
    }
    return res;
  }
};

int main() {
	string a = "abbaca";
	Solution sln;
	cout << sln.removeDuplicates(a) << endl;
	return 0;
}