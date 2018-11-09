#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;
typedef vector<bool> lst_b;

class Graph{
	public:
		int v;
		list<int> *neighbours;
		Graph(int num){
			v=num;
			neighbours=new list<int>[num];
		}
		void edge(int i, int j){
			neighbours[i].push_back(j);
		}
};

bool detect_cycle(Graph &g, lst_b &global, lst_b &local, int curr){
	if(!global[curr]){
		global[curr]=true;
		local[curr]=true;
		list<int> tp=g.neighbours[curr];
		for(auto k: tp){
			if(!global[k]&&detect_cycle(g,global,local,k)) return true;
			else if(local[k]) return true;
		}	
	}
	local[curr]=false;
	return false;
}

bool lol(){
	Graph g(4);
	g.edge(0,1);
	g.edge(0,2);
	g.edge(2,3);
	g.edge(1,2);
	g.edge(2,0);
	g.edge(3,3);
	vector<bool> global(4,false);
	vector<bool> local(4,false);
	for(int k=0; k<4; k++){
		if(detect_cycle(g,global,local,k)) return true;
	}
	return false;
}

int main(){
	cout<<lol()<<endl;
	return 0;
}