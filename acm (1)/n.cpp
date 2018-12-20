
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	string a,b; cin>>a>>b;
	int x=0;
	int size=min(a.size(), b.size());
	for(int i=0;i<size;i++){
		if(a[i]==b[i]) x++;
	}
	int y=size-x;
	int nn=size-n;
	cout<<(min(x,n)+min(y,nn))<<endl;
}

