#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vi;


int main() {
	int cases,n,t,m;
	cin>>cases;
	while(cases--) {
		cin>>n>>t>>m;
		queue<pt> LQ, RQ;
		for(int k=0; k<m; k++){
			int x; string y; cin>>x>>y;
			y=="left" ? LQ.push({x,k}) : RQ.push({x,k});
		}
		bool side = 0;
		int time = 0;
		vi ans(m);
		while(!(LQ.empty() && RQ.empty())) {
			// if the ferry has to wait
			int ff = INT_MAX;
			if(!LQ.empty()) ff = LQ.front().first;
			if(!RQ.empty()) ff = min(ff,RQ.front().first); 
			time = max(ff,time);

			if(!side) {	
				for(int k=0; k<n; k++) {
					if(!LQ.empty() && LQ.front().first <= time) {
						ans[LQ.front().second] = time + t;
						LQ.pop();
					}
				}
			}
			else {
				for(int k=0; k<n; k++) {
					if(!RQ.empty() && RQ.front().first <= time) {
						ans[RQ.front().second] = time + t;
						RQ.pop();
					}
				}
			}

			time += t;
			side = !side;
		}
		for(auto a: ans) cout << a << endl;
		if(cases) cout << endl;
	}
	return 0;
}