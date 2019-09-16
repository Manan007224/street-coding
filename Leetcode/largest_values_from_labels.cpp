#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct cmp {
	bool operator() (pii &a, pii &b) {
		return a.first > b.first;
	} 
};

class Solution {
public:
  int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
    cmp c;
    vector<pii> x; int res = 0;
    for(int i=0; i<values.size(); i++) x.push_back({values[i], labels[i]});
    unordered_map<int,int> mp;
  	int k = 0;	
    sort(x.begin(), x.end(), c);
  	for(int i=0; i<x.size(); i++) {
  		if(k == num_wanted) break;
      int l = x[i].second;
      if(mp.find(l) == mp.end()) {
        res += x[i].first;
        mp.insert({l, 1});
        ++k;
      }
  		else if(mp[l] < use_limit) {
  			res += x[i].first;
  			mp[l]++;
        ++k;
  		}
  	}
  	return res;
  }
};

int main() {
	return 0;
}