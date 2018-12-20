
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,c; cin>>n>>c;
	vector<int> v(n, 0);
	bool first=true;
	while(c--){
		int a; cin>>a;
		int mm=v[0];
		int x=0;
		for(int i=1;i<n;i++){
			if(v[i]<mm){
				mm=v[i];
				x=i;
			}
		}
		if(first) first=false;
		else cout<<' ';
		cout<<(x+1);
		v[x]+=a;
	}
	cout<<endl;
}
