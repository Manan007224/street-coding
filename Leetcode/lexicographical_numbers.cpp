#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> lexicalOrder(int n) {
  	vector<int> R;
  	for(int i=1; i<=9; i++) {
  		if(i > n) break;
  		R.push_back(i);
  		go(i, n, R);
  	}
  	return R;
  }

  void go(int n, int t, vector<int> &R) {
		for(int i=0; i<=9; i++) {
			int next = n * 10 + i;
			if(next > t) break;
			R.push_back(next);
			go(next, t, R);
		}
	}
};

int main() {
	Solution sln;
	vector<int> res = sln.lexicalOrder(23);
	for(auto r: res) cout << r << " ";
	cout << endl;
	return 0;
}