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
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if(n==0) return 0;
    unordered_set<int> dict;
    int i=1, j=0, res=1;
    dict.insert(s[0]);
    while(i<n && j<n) {
    	auto at_i = dict.find(s[i]);
    	auto at_j = dict.find(s[j]);
    	if(at_i!=dict.end()) {
    		dict.erase(at_j);
    		j++;
    	}
    	else {
    		dict.insert(s[i]);
    		i++;
    	}
    	res = max(res, i-j);
    }
    return res;
  }
};

int main() {
	string s = "pwwkew";
	string s1 = "abcabcbb";
	string s2 = "aaaaaa";
	string s3 = "a";
	Solution sln;
	cout << sln.lengthOfLongestSubstring(s2) << endl;
	cout << sln.lengthOfLongestSubstring(s3) << endl;
	return 0;
}