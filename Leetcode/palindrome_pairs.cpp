#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
  	int n = words.size();
  	unordered_map<string,int> mp;
  	vector<vector<int>> res;
  	for(int i=0; i<n; i++) mp[words[i]]=i;
  	for(int i=0; i<n; i++) {
  		string rv = words[i];
      string empty = "";
  		reverse(rv.begin(), rv.end());
  		if(mp.find(rv)!=mp.end() && mp[rv]!=i)
  			res.push_back({i,mp[rv]});
      if(mp.find(empty)!=mp.end() && mp[empty]!=i && is_palindrome(rv,0,rv.length()-1))
        res.push_back({mp[empty],i});
  	}
  	for(int i=0; i<n; i++) {
  		int k = words[i].length();
  		for(int j=0; j<k; j++) {
  			bool after = is_palindrome(words[i],j,k-1);
  			bool before = (j>0 && is_palindrome(words[i],0,j-1));
  			if(after) {
  				string sfx = words[i].substr(0,j);
  				reverse(sfx.begin(),sfx.end());
  				if(mp.find(sfx)!=mp.end() && mp[sfx]!=i)
  					res.push_back({i,mp[sfx]});
  			}
  			if(before) {
  				string pfx = words[i].substr(j);
  				reverse(pfx.begin(),pfx.end());
  				if(mp.find(pfx)!=mp.end() && mp[pfx]!=i)
  					res.push_back({mp[pfx],i});
  			}
  		}
  	}
  	return res;    
  }

  bool is_palindrome(string s, int i, int j) {
  	while(i<j) {
  		if(s[i++]!=s[j--]) return 0;
  	}
  	return 1;
  }
};

int main() {
	vector<string> t = {"abcd","dcba","lls","s","sssll"};
	vector<string> t1 = {"bat", "tab", "cat"};
 	Solution sln;
	vector<vector<int>> res = sln.palindromePairs(t1);
	for(auto rr : res) {
		for(auto r : rr) cout << r << " ";
		cout << endl;
	}
	return 0;
}