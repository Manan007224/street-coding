#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	while(1) {
		int n; cin>>n; 
		if(n==0) break;
		while(1) {
			vi a(n);
			stack<int> coach;
			int j = 0, t;
			cin >> a[0];
			if(a[0] == 0){
				cout<<endl;
				break;
			}
			for(int i=1; i<n; i++) cin >> t, a[i] = t;
			for(int i=1; i<=n; i++) {
				coach.push(i);
				while(!coach.empty()) {
					if(coach.top() == a[j]) {
						coach.pop();
						j++;
					}
					else break; 
				}
			}
			if(coach.empty()) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}