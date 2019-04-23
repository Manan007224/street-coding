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
  int longestSubstring(string s, int k) {
    return go(s,k);
  }

	int go(string s, int k) {
		if(s.length()<1){
			cout << "came here" << endl;
			return 0;
		}
		vector<int> rec(26,0);
    for(int i=0; i<s.length(); i++)
    	rec[s[i]-'a']++;
    int start = 0;
    while(start < s.length() && rec[s[start]-'a'] < k)
    	start++;
    for(int i=start; i<s.length(); i++) {
    	if(rec[s[i]-'a']<k) {
    		string x = s.substr(start,i-start);
    		string y = s.substr(i+1,-1);
    		return max(go(x,k), go(y,k));
    	}
    }
    return s.length() > start ? s.length()-start : 0;
	}
};

int main() {
	string str = "ababbcdddfff";
	string str1 = "ababbc";
	string str2 = "baaabcb";
	Solution sln;
	cout << sln.longestSubstring(str2,3) << endl;
	return 0;
}