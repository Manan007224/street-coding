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
  vector<int> topKFrequent(vector<int>& nums, int k) {
  	int n = nums.size();
    vector<int> res;
    unordered_map<int,int> rec;
    for(auto n: nums) rec[n]++;
    vii buckets(n+1);
  	for(auto r: rec) buckets[r.se].pb(r.fi);
  	for(int i=n; i>=0; i--) {
  		for(int j=0; j<buckets[i].size(); j++) {
  			res.pb(buckets[i][j]);
  			if(res.size()==k) return res;
  		}
  	}
  	return res;
  }
};

int main() {
	vector<int> t = {1,1,1,1,2,2,3,4};
	vector<int> t1 = {1};
	Solution sln;
	vector<int> res = sln.topKFrequent(t, 2);
	for(auto r: res) cout << r << endl;
	return 0;
}