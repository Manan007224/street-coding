#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<vector<int>> llst;

int main(){
    string a,b;
    string a1="";
    string b1="";	
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	int t1=a.size();
	int t2=b.size();
	llst M(t1,lst(t2,-1));
	for(int x1=0;x1<t1;x1++) M[x1][0]=x1*2;
	for(int x2=0;x2<t2;x2++) M[0][x2]=x2*2;
	for(int x1=1;x1<t1;x1++){
		for(int x2=1;x2<t2;x2++){
			int cc=(a[x1]!=b[x2])?2:0;
			M[x1][x2]=min({M[x1-1][x2-1]+cc,M[x1-1][x2]+2,M[x1][x2-1]+2});
		}
	}
	for(int x1=0;x1<t1;x1++){
		for(int x2=0;x2<t2;x2++){
			cout<<M[x1][x2]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
