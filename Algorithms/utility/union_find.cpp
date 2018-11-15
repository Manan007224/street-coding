#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;

class Graph{
public:
	int v;
	list<int> *adj;
	lst parent;
	lst rank;

	Graph(int num){
		v=num;
		adj=new list<int>[num];
	}

	void edge(int i, int j){
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	int find_parent(int x, int y){
		
	}

	void union(){
		
	}

	void print_levels(){
		
	}
};


int main(){

	return 0;
}