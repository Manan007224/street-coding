#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void go(int start, vector<int> &curr, int n) {
	if(start == n){
		res.push_back(curr);
		return;
	}
	curr[start] = 0;
	go(start+1, curr, n);
	curr[start] = 1;
	go(start+1, curr, n);
}

int main() {
	int n = 3;
	vector<int> curr(n);
	go(0, curr, n);
	for(auto rr : res) {
		for(auto r : rr) cout << r << " ";
		cout << endl;
	}
	return 0;
}