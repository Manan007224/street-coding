#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shortestWay(string source, string target) {
  	unordered_map<char, set<int>> mp;
  	for(int i=0; i<source.length(); i++) mp[source[i]].insert(i);
  	int j = -1, res = 1;
  	for(int i=0; i<target.length(); i++) {
  		if(mp.find(target[i]) == mp.end()) return -1;
  		set<int> st = mp[target[i]];
  		auto tp = st.upper_bound(j);
  		if(tp == st.end()) {
  			res++;
  			j = *st.begin();
  		}
  		else j = *(tp);
  	}
  	return res;
  }
};

int main() {
	Solution sln;
	cout << sln.shortestWay("abcab", "aabbac") << endl;
	return 0;
}