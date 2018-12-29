

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<int,int>> v(n);
	for(auto& x: v) cin>>x.first>>x.second;
	for(int i=n;i>0;i--){
		int c=n-i;
		bool works=true;
		for(int j=0;j<n;j++){
			if(i>=v[j].first && i<=v[j].second){}
			else{
				c--;
				if(c<0){
					works=false;
					break;
				}
			}
		}
		if(c==0){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}

