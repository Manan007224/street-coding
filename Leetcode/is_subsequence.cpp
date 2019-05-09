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
  bool isSubsequence(string s, string t) {
 		int a = s.length(), b = t.length(), j = 0;
 		for(int i=0; i<b; i++){
      if(t[i]==s[j]) j++;
      if(j==a) break;
    } 
 		return j==a;    
  }
};

int main() {
	string s = "abc", t = "ahbcgdc";
	Solution sln;
	cout << sln.isSubsequence(s,t) << endl;
	return 0;
}