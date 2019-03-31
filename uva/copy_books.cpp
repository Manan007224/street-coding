#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;

int main() {
	int t; cin>>t;
	while(t--){
		int m,k; cin>>m>>k;
		vi p(m);
		for(int i=0; i<m; i++) cin>>p[i];
		ll hi = accumulate(p.begin(),p.end(),0ll);
		ll lo = *max_element(p.begin(),p.end());
		vector<int> mask;
		while(lo<hi) {
			mask.clear();
			ll mid = lo+(hi-lo)/2, res = 0;
			for(int i=m-1; i>=0;) {
				ll sum = 0;
				while(i>=0 && sum+p[i]<=mid){
					sum += p[i], i--;
				}
				if(sum==0) {
					res = k+1;
					break;
				} 
				mask.push_back(i);
				res++;
			}
			res<=k ? hi=mid : lo=mid+1;
			if((hi+lo)/2==mid) break;
		}
		if(mask.size()>0) mask.pop_back();
		int cnt=0;
		for(int i=0;i<m;i++) {
			cout<<p[i]<<" ";
			if(mask.size()>0 && mask[mask.size()-1]==i && cnt<k-1) {
				cout<<"/ ";
				cnt++;
				mask.pop_back();
			}
		}
		cout<<endl;

	}
	return 0;
}