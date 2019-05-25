#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
  	int n = S.length();
  	unordered_map<char,int> F;
  	string res = "";
  	for(auto c : S) F[c]++;
  	vector<vector<char>> B;
  	for(auto f : F) B[f.second].push_back(f.first);
  	for(int i=0; i<B.size(); i++) {
  		for(int j=0; j<B[i].size(); j++) {
  			for(int k=0; k<i; k++) {
  				res += B[i][j];
  			}
  		}
  	}
  	return res;  
  }
};

int main() {
	return 0;
}