#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> lst;
typedef long long ll;

ll cost(lst &stalls, ll cows, ll mn, ll cs){
	if(cows==0) return mn;
	ll ff=-1;
	for(ll k=cs+1;k<stalls.size();k++){
		if(cows-1<=stalls.size()-k){
			ll store =(k!=0)?min(mn,stalls[k]-stalls[cs]):mn;
			ll cc=cost(stalls,cows-1,store,k);
			ff=max(cc,ff);
		}
	}
	return ff;
}


int main(){
	//lst stalls={1,2,4,8,9};
	int t; cin>>t;
	while(t-- >0){
		int n,c;
		cin>>n>>c;
		lst stalls;
		while(n-- >0){
			ll tp; cin>>tp;
			stalls.push_back(tp);
		}
		sort(stalls.begin(),stalls.end());
		ll ans=cost(stalls,c,numeric_limits<ll>::max(),-1);
		cout<<ans<<endl;
	}
	return 0;
}