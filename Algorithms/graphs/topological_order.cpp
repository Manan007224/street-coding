#include <bits/stdc++.h>
using namespace std;

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

void topSort(Graph &g, vector<bool> &v, stack<int> &st, int curr){
	// if(v[curr])
	// 	return;
	v[curr]=true;
	list<int> tp=g.neighbours[curr];
	for(auto const& k:tp){
		if(!v[k])
			topSort(g,v,st,k);
	}
	st.push(curr);
}

// void topSortD(Graph &g){
// 	Graph g1;
// 	for(int i=0;i<g.v;i++){
// 		list<int> tp=g.neighbours[i];
// 		for(auto const& j: tp){
// 			g1.neighbours[j].push_back(i);
// 		}
// 	}
// 	vector<bool> v(8,false);
// 	vector<int> count(8);
// 	for(auto const& k: count)
// 		count[k]=g1.neighbours[k].size();
// 	int cnt=0;
// 	while(cnt<8){

// 	}
// }

void print_graph(Graph g){
	for(int k=0;k<g.v;k++){
		list<int> tp=g.neighbours[k];
		cout<<k<<": ";
		for(auto const& i: tp)
			cout<<i<<", ";
		cout<<endl;
	}
}

int main(){
	int sz=6;
	Graph g(8);
	g.edge(0,2); g.edge(1,2); g.edge(2,4);
	g.edge(1,3); g.edge(3,5); g.edge(5,6);
	g.edge(4,5); g.edge(4,7);
	Graph g1(sz);
	g1.edge(0,2); g1.edge(0,3); g1.edge(1,0); g1.edge(1,2);
	Graph g2(6);
	g2.edge(5,2); g2.edge(5,0); g2.edge(4,0); g2.edge(4,1); g2.edge(2,3); g2.edge(3,1);
	vector<bool> v(sz,false);
	stack<int> st;
	for(int k=0;k<sz;k++){
		if(!v[k]){
			//cout<<k<<endl;
			topSort(g2,v,st,k);
		}
	}
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}