#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (string &a, string &b) {
		return a.length() < b.length();
	}
};

class Solution {
public:
  int longestStrChain(vector<string>& words) {
  	int n = words.size();
    int res = 1;
  	cmp c;
  	sort(words.begin(), words.end(), c);
  	vector<int> dp(n, 1);
  	for(int i = 1; i < n; ++i) {
  		for(int j = 0; j < i; ++j) {
  			unordered_map<int,int> rec;
  			int k = 0;
  			for(auto x : words[i]) rec[x]++;
  			for(auto x : words[j]) rec[x]--;
  			for(auto r : rec) {
  				if(r.second != 0) ++k;
  			}
  			if(abs(k) == 1){
  				dp[i] = max(dp[i], dp[j]+1);
          res = max(res, dp[i]);
  			}
  		}
  	}
  	return res;
  }
};

int main() {
	Solution sln;
	vector<string> arr = {"sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz"};
	cout << sln.longestStrChain(arr) << endl;
  string s1 = "abc", s2 = "ba";
	return 0;
}