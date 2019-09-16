#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t>0) {
		int r; cin>>r; vector<int> streets(r);
		for(int i=0; i<r; i++) cin>>streets[i];
		sort(streets.begin(),streets.end());
		int md = streets[r/2], res=0;
		for(int i=0; i<r; i++) res += abs(md-streets[i]);
		cout << res << endl;
	}
	return 0;
}