#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  vector<int> numsSameConsecDiff(int N, int K) {
  	vector<vector<int>> res;
    int i = N <= 1 ? 0 : 1;
  	for(; i<=9; i++) {
  		if(i+K <= 9 || abs(i-K) >= 0) go({i}, N-1, K, res);
  	}
  	vector<int> ans;
  	for(auto r: res) {
  		int a = 0, x = r.size()-1;
  		for(int k=x; k>=0; k--) a += r[k] * pow(10, x-k); 
  		ans.push_back(a);
  	}
  	return ans;
  }

  void go(vector<int> v, int n, int k, vector<vector<int>> &res) {
  	if(n==0){
  		res.push_back(v);
  		return;
  	}
  	int x = v[v.size()-1];
    if(k==0) {
      vector<int> vf = v; vf.push_back(x+k);
      go(vf, n-1, k, res);
    }
    else {
      if(x+k <= 9) {
	  		vector<int> vf = v;
	  		vf.push_back(x+k);
	  		go(vf, n-1, k, res);
	  	}
	  	if(x-k >= 0) {
	  		vector<int> vf = v;
	  		vf.push_back(x-k);
	  		go(vf, n-1, k, res);
	  	} 
    }
  }
};

int main() {
	Solution sln;
	vector<int> res = sln.numsSameConsecDiff(2, 1);
	for(auto r: res) cout << r << endl;
	return 0;
}