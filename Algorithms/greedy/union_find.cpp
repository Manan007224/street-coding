#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;

int find(lst &p,int x){return (p[x]==x)?x:find(p,p[x]);}
void join(lst &p,int x1,int x2){p[find(p,x1)]=find(p,x2);}

int main(){
	int t=4;
	lst p(t,-1);
	for(int x=0;x<t;x++) p[x]=x;
	join(p,0,1);
	join(p,1,2);
	join(p,2,3);
	for(auto x:p) cout<<x<<endl;
	return 0;
}