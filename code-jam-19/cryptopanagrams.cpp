#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
	ll T; cin>>T;
	for(ll t=0; t<T; t++) {
		ll n,l; cin>>n>>l;
		vi p(l);
		vi png;
		for(ll i=0;i<l;i++) cin>>p[i];
		unordered_map<ll,char> mp;
		ll x;
		for(ll i=0;i<l-1;i++) {
			x = __gcd(p[i],p[i+1]);
			if(i==0) png.push_back(p[0]/x);
			png.push_back(x);
			if(i==l-2) png.push_back(p[i+1]/x);
		}
		unordered_set<ll> plist(png.begin(),png.end());
		vi og(plist.begin(),plist.end());
		sort(og.begin(),og.end());
		for(ll i=0; i<og.size(); i++) {
			mp[og[i]] = ('A'+i);
		}
		string ans = "";
		for(ll i=0; i<png.size(); i++) ans += mp[png[i]];
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}