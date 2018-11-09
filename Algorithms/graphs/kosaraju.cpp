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

void DFS(Graph &g, stack<int> &st, vector<bool> &v, int curr){
	if(v[curr])
		return;
	v[curr]=true;
	list<int> tp=g.neighbours[curr];
	for(auto k=tp.begin();k!=tp.end();k++){
		if(!v[*k])
			DFS(g,st,v,*k);
	}
	st.push(curr);
}

void reverse_DFS(Graph &g, stack<int> &st, vector<bool> &v, int curr){
	cout<<curr<<" ";
	if(v[curr])
		return;
	v[curr]=true;
	st.pop();
	list<int> tp=g.neighbours[curr];
	for(auto k=tp.begin();k!=tp.end();k++){
		if(!v[*k])
			reverse_DFS(g,st,v,*k);
	}
}

void reverse(Graph &g, Graph &g1){
	for(int i=0;i<g.v;i++){
		list<int> tp=g.neighbours[i];
		for(auto j=tp.begin();j!=tp.end();j++){
			g1.neighbours[*j].push_back(i);
		}
	}
}


void print_graph(Graph g){
	for(int k=0;k<g.v;k++){
		list<int> tp=g.neighbours[k];
		cout<<k<<": ";
		for(auto i=tp.begin();i!=tp.end();i++)
			cout<<*i<<", ";
		cout<<endl;
	}
}

void kosaraju(Graph g){
	vector<bool> v(11,false);
	stack<int> st;
	for(int k=0;k<11;k++){
		if(!v[k])
			DFS(g,st,v,k);
	}
	Graph g1(11);
	vector<bool> v1(11,false);
	reverse(g,g1);
	while(!st.empty()){
		if(!v1[st.top()]){
			reverse_DFS(g1,st,v1,st.top());
			cout<<endl;
			cout<<"#####################"<<endl;
		}
	}
}


int main(){
	Graph g(11);
	g.edge(0,1); g.edge(2,0); g.edge(1,2);
	g.edge(1,3);
	g.edge(3,4); g.edge(4,5); g.edge(5,3);
	g.edge(6,5);
	g.edge(6,7); g.edge(7,8); g.edge(8,9); g.edge(9,6);
	g.edge(9,10);
	kosaraju(g);
	return 0;
}