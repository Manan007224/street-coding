#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> pii;

struct cmp {
	bool operator() (pii &a, pii &b) {
		return a.second < b.second;
	} 
};

class Solution {
public:
  string reorganizeString(string S) {
  	unordered_map<char,int> mp;
  	priority_queue<pii,vector<pii>,cmp> pq;
  	int allowed = (S.length()%2 == 0) ? S.length()/2 : S.length()/2+1;
  	for(auto c:S) {
  		mp[c]++;
  		if(mp[c]>allowed) return "";
  	}
   	for(auto m:mp) pq.push({m.first,m.second});
  	string res;
  	for(int i=0;i<S.length();i++) res+='#';
  	int odd=0, even=1;
  	while(!pq.empty()) {
  		pii now=pq.top(); pq.pop();
  		int k=now.second;
  		while(odd<S.length() && k>0) {
  			res[odd]=now.first;
  			k--;
  			odd+=2;
  		}
  		while(even<S.length() && k>0) {
  			res[even]=now.first;
  			k--;
  			even+=2;
  		}
  	}
  	return res;	
  }
};

int main() {
	Solution sln;
	cout << sln.reorganizeString("aaaabbcc") << endl;
	return 0;
}