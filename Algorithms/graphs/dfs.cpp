#include <bits/stdc++.h>
using namespace std;

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

int main(){
	Graph g2(6);
	g2.edge(5,2); g2.edge(5,0); g2.edge(4,0); g2.edge(4,1); g2.edge(2,3); g2.edge(3,1);
	lst_b v(6,false);
	stack<int> st;
	st.push(5);
	while(!st.empty()){
		int cr=st.top();
		st.pop();
		list<int> tp=g2.neighbours[cr];
		for(auto const& k: tp){
			if(!v[k]){
				cout<<k<<endl;
				v[k]=true;
				st.push(k);
			}
		}
	}
	return 0;
}

