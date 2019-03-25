#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	int y; cin>>y;
	int p; cin>>p;
	vi v(p);
	int res = 0, s, e;
	for(int i=0; i<p; i++) cin>>v[i];
	for(auto it=v.begin(); it!=v.end(); it++) {
		auto up = upper_bound(v.begin(),v.end(),(*it+y-1));
		if(up-it>res) {
			res = up - it;
			s = *it;
			e = *(up-1);
		}
	}
	cout<<res<<" "<<s<<" "<<e<<endl;
	return 0;
}