#include <bits/stdc++.h>
using namespace std;



void join(vector<int>& p,int x1,int x2){
	int cr=x1;
	while(p[cr]!=cr){
		cout<<cr<<endl;
		cr=p[x1];
		p[cr]=x2;
	}
	p[cr]=x2;
}

int main(){
	vector<int> p(6);
	for(int i=0;i<6;i++) p[i]=i;
	p[0]=1;
	p[1]=2;
	p[2]=2;
	p[3]=3;
	join(p,0,3);
	for(auto x:p)cout<<x<<" ";
	cout<<endl;
	return 0;
}