#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> p(n), d(n);
	for(int i=0; i<n; i++) {
		cin >> p[i];
		cin >> d[i];
	}
	int idx = 0;
	int total_cost = 0, curr_cost = 0;
	for(int i=0; i<n; i++) {
		total_cost += p[i] - d[i];
		curr_cost += p[i] - d[i];
		if(curr_cost < 0) {
			idx = i+1;
			curr_cost = 0;
		}
	}
	cout << idx << endl;
	return 0;
}