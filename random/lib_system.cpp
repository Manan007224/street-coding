#include <bits/stdc++.h>
using namespace std;

void swap(pair<int,int> &x, pair<int,int> &y){
	pair<int,int> t;
	t.first = x.first; t.second = x.second;
	x.first = y.first; x.second = y.second;
	y.first = t.first; y.second = t.second;
}

void insert(vector<pair<int,int>> &Heap, pair<int,int> range){
	Heap.push_back(range);
	for(int i=Heap.size()-1;i>1;i=i/2){
		if(Heap[i].first<Heap[i/2].first)
			swap(Heap[i],Heap[i/2]);
		else
			break;
	}
}

bool search_booking(vector<pair<int,int>>, pair<int,int> time) {
	
}	

int main() {
	pair<int,int> nl(-1,1);
	pair<int,int> fs(3,6);
	pair<int,int> ss(9,13);
	pair<int,int> th(22,25); 
	vector<pair<int,int>> Hp;
	Hp.push_back(nl);
	Hp.push_back(fs);
	Hp.push_back(ss);
	Hp.push_back(th);
	pair<int,int> nn(1,2);
	insert(Hp,nn);
	for(int i=0;i<Hp.size();i++) cout << Hp[i].first << " " << Hp[i].second << " " << endl;
	return 0;
}