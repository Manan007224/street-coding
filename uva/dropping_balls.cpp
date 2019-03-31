#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1){
		int t; cin>>t;
		if(t==-1) break;
		while(t--) {
			int d, i,res = 1; cin>>d>>i;
			d--;
			while(d--) {
				res = (i%2 == 1) ? res*2 : res*2+1;
				i -= (i/2); 
			}
			cout<<res<<endl;
		}
	}
	return 0;
}