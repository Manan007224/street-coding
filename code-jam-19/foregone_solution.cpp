#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t; cin >> t;
	for(ll i=1; i<=t; i++) {
		ll n; cin>>n;
		ll a=n, b=0, x=1;
		while(n>0) {
			if(n%10==4){
				b += x;
				a -= x;
			}
			n /= 10;
			x *= 10;
		}
		cout<<"Case #"<<i<<" "<<a<<" "<<b<<endl;
	}
	return 0;
}