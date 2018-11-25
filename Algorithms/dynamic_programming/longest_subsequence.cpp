#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;

int main(){
	string a,b;
	cin>>a>>b;
	int t1=a.size()+1;
	int t2=b.size()+1;
	llst(t1,lst(t2,-1));
	for(int x1=0;x1<t1;x1++) llst[0][x1]=0, llst[x1][0]=0;
	for(int x1=1;x1<t1;x1++){
		for(int x2=1;x2<t2;x2++){
			
		}
	}
	return 0;
}