#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxRepOpt1(string text) {
  	int n = text.length();
  	vector<vector<int>> rec(26);
  	int res = 1;
  	for(int i=0; i<n; i++) rec[text[i]-'a'].push_back(i);
  	for(int i=0; i<26; i++) {
  		int curr = 1, prev = 0;
  		int mx = 0;
  		for(int j=1; j<rec[i].size(); j++) {
  			if(rec[i][j-1]+1 == rec[i][j]) curr++;
  			else {
  				if(idx[i][j-1] + 2 == idx[i][j]) prev = curr;
  				else prev = 0;
  				curr = 0;
  			}
  			mx = max(mx, curr + prev);
  		}
  		res = max(res, mx + (rec[i].size() > mx ? 1 : 0));
  	}
  }
};

int main() {
	return 0;
}