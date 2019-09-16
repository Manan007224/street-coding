#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
  	unordered_map<string, int> mp1, mp2, mp3;
  	vector<string> res;
  	int n = wordlist.size();
  	int m = queries.size();
  	for(int i=0; i<n; i++) {
  		mp1[wordlist[i]] = i;
  		string data = wordlist[i];
  		transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return tolower(c); });
    	if(mp2.find(data) == mp2.end()) {
    		mp2[data] = i;
    	}
    	string data1 = rv(data);
    	if(mp3.find(data1) == mp3.end()) {
    		mp3[data1] = i;
    	}
  	}

  	for(int i=0; i<m; i++) {
  		if(mp1.find(queries[i]) != mp1.end()) {
  			res.push_back(wordlist[mp1[queries[i]]]);
  			continue;
  		} 
  		string data = queries[i];
  		transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return tolower(c); });
    	if(mp2.find(data) != mp2.end()) {
    		res.push_back(wordlist[mp2[data]]);
    		continue;
    	}
    	string data1 = rv(data);
    	if(mp3.find(data1) != mp3.end()) res.push_back(wordlist[mp3[data1]]);
    	else res.push_back("");
  	}
  	return res;
  }

  bool is_vowel(char c) {
  	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
  }

  string rv(string data) {
  	string data1 = "";
  	for(auto d: data) {
  		if(is_vowel(d)) data1 += "*";
  		else data1 += d;
  	}
  	return data1;
  }
};

int main() {
	Solution sln;
	vector<string> w = {"KiTe","kite","hare","Hare"};
	vector<string> q = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
	vector<string> res = sln.spellchecker(w, q);
	for(auto r: res) cout << r << endl;
	return 0;
}