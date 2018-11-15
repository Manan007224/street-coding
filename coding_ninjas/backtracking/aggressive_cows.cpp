#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> lst;
typedef long long ll;
typedef numeric_limits<long long>::max() smax;

ll cost(lst &dx,ll cw,ll mn,ll cs){
	if(cw==0) return mn;
	ll ff=-1;
	for(ll k=cs+1;k<dx.size();k++){
		if(cw-1<=dx.size()-k){
			ll x =(k!=0)?min(mn,dx[k]-dx[cs]):mn;
			ll cc=cost(dx,cw-1,x,k);
			ff=max(cc,ff);
		}
	}
	return ff;
}


int main(){
	//lst st={1,2,4,8,9};
	int t; cin>>t;
	while(t-- >0){
		int n,c;
		cin>>n>>c;
		lst dx;
		while(n-- >0){
			ll tp; cin>>tp;
			dx.push_back(tp);
		}
		sort(dx.begin(),dx.end());
		ll ans=cost(dx,c,smax,-1);
		cout<<ans<<endl;
	}
	return 0;
}