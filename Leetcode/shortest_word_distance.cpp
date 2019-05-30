#include <bits/stdc++.h>
using namespace std;

class WordDistance {
public:
  WordDistance(vector<string>& words) {
  	for(int i=0; i<words.size(); i++) rec[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
  	vector<int> x = rec[word1], y = rec[word2];
  	int lo = 0, hi = 0;
  	int res = INT_MAX;
  	while(lo < x.size() && hi < y.size()) {
  		res = min(abs(lo-hi),res);
  		if(x[lo] < y[hi]) lo++;
  		else hi++;
  	}
  }
private:
	unordered_map<string,vector<int>> rec;
};

int main() {
	return 0;
}