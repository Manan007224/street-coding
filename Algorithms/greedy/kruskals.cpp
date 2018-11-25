#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
typedef pair<int,int> pt;
typedef vector<int> lst;
typedef vector<pair<int,pair<int,int>>> Graph;

int find(lst &p,int x){return (p[x]==x)?x:find(p,p[x]);}
void join(lst &p,int x1,int x2){p[find(p,x1)]=find(p,x2);}

int main(){
	int e; cin>>e;
	Graph g;
	lst p(e);
	vector<pt> MST;
	int weight=0;
	for(int x=0;x<e;x++) p[x]=x;
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back(make_pair(w,make_pair(u,v)));
	}
	sort(g.begin(),g.end());
	for(auto x:g){
		int u=x.second.first;
		int v=x.second.second;
		if(find(p,u)!=find(p,v)){
			MST.push_back(make_pair(u,v));
			weight+=x.first;
			join(p,u,v);
		}
	}
	for(auto x:MST) cout<<x.first<<" "<<x.second<<endl;
	cout<<"weight of MST is: "<<weight<<endl;
	return 0;
}

/*
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

6 7
2 8
5 6
0 1
2 5
2 3
0 7
3 4
weight of MST is: 37
*/