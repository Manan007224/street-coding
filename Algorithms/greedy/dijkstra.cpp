#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 
typedef pair<int,int> pt;
typedef vector<int> lst;
typedef vector<vector<pt>> Graph;

int main(){
	int n;cin>>n;
	Graph g(n);
	lst dist(n,INF);
	vector<bool> flag(n,false);
	for(int i=0;i<n;i++){
		int m; cin>>m;
		for(int j=0;j<m;j++){
			int vt, dt;
			cin>>vt>>dt;
			g[i].push_back(make_pair(dt,vt));
		}
	}
	priority_queue<pt, vector<pt>, greater<pt>> pq; //weird c++ syntax
	pq.push(make_pair(0,0));
	dist[0]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		flag[u]=true;
		for(auto x:g[u]){
			int v=x.second;
			int w=x.first;
			if(!flag[v] && dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	for(auto x:dist) cout<<x<<endl;
	return 0;
}

/*
6
3 1 50 2 45 3 10
2 2 10 3 15 
1 4 30
2 0 10 4 15
2 1 20 2 35
1 4 3

0
45
45
10
25
1061109567
*/