#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1e9 + 7;

class Solution {
public:
  int threeSumMulti(vector<int>& A, int target) {
  	unordered_map<int,int> f;
  	for(auto a: A) f[a]++;
  	LL res = 0;
  	for(auto x : f) {
  		for(auto y : f) {
  			int i = x.first, j = y.first, k = target - (i+j);
  			if(f.find(k) != f.end()) {
  				if(i == j && j == k) res += f[i] * (f[i]-1) * (f[i]-2) / 6;
  				else if(i == j && j != k && f[i] >= 2) res += f[i] * (f[i]-1) / 2 * f[k];
  				else if(i < j && j < k) res += f[i] * f[j] * f[k];
  			}
  		}
  	}
  	return res % M;
  }
};


int main() {
	vector<int> t = {1,1,2,2,3,3,4,4,5,5};
	Solution sln;
	cout << sln.threeSumMulti(t, 8) << endl;
	return 0;
}