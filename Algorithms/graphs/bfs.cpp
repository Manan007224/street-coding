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
			neighbours[j].push_back(i);
		}
};

int main(){
	Graph test(4);
	test.edge(0,1);
	test.edge(1,3);
	test.edge(2,3);
	test.edge(0,2);
	test.edge(0,3);
	for(int k=0;k<test.v;k++){
		list<int> tp=test.neighbours[k];
		for(auto i=tp.begin();i!=tp.end();i++)
			cout<<*i<<" "<<endl;
		cout<<endl;
	}
	return 0;
}