#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
typedef pair<int,int> pt;
typedef vector<int> lst;
typedef vector<vector<pt>> Graph;

int main(){
	int e; cin>>e;
	Graph g(e);
	vector<bool> flag(e,false);
	lst dist(e,INF);
	lst MST(e);
	for(int i=0;i<e;i++){
		int m; cin>>m;
		for(int j=0;j<m;j++){
			int vt,dt;
			cin>>vt>>dt;
			g[i].push_back(make_pair(dt,vt));
			g[vt].push_back(make_pair(dt,i));
		}	
	}
	priority_queue<pt,vector<pt>,greater<pt>> pq;
	pq.push(make_pair(0,0));
	MST[0]=0;
	while(!pq.empty()){
		auto pp=pq.top();
		int u=pq.top().second;
		pq.pop();
		flag[u]=true;
		for(auto x:g[u]){
			int v=x.second;
			int w=x.first;
			if(!flag[v] && dist[v]>w){
				pq.push(make_pair(w,v));
				dist[v]=w;
				MST[v]=u;
			}
		}
	}
	for(int x=1;x<e;x++) cout<<x<<" "<<MST[x]<<endl;
	int sum=0;
	for(int x=1;x<e;x++) sum+=dist[x];
	cout<<"weight of the MST is: "<<sum<<endl; 
	return 0;
}

/*
7	
2 1 28 5 10
2 2 16 6 4
1 3 12
2 6 18 4 22
2 25 5 6 24
0
0

1 2
2 3
3 4
4 5
5 0
6 1
weight of the MST is: 99
*/