#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
typedef pair<int,int> pt;
typedef vector<int> lst;
typedef vector<pair<int,pt>> Graph;

int main(){
	int n,e; cin>>n>>e;
	Graph g(n);
	lst dist(n,INF);
	for(int x=0;x<e;x++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({w,{u,v}});
	}
	dist[0]=0;
	for(int i=1;i<n;i++){
		bool updated=false;
		for(auto x:g){
			int u=x.second.first;
			int v=x.second.second;
			int w=x.first;
			if(dist[u]!=INF && dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				updated=true; // atleast one value updated
			}
		}
		if(!updated) break;
	}
	for(auto x:dist) cout<<x<<endl;
	return 0;
}

/*
7 10
0 1 6
0 2 5 
0 3 5
1 4 -1
2 1 -2
2 4 1
3 2 -2
3 5 -1
4 6 3
5 6 3

0
1
3
5
0
4
3
*/