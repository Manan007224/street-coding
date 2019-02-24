#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<node*> children;
	bool is_end;
	node(){
		children=vector<node*>(26,NULL);
		is_end=false;
	}
};

class Trie{
private:
	node* root;
public:
	Trie(){root=new node();}
	void insert(string word){
		
	}
};	

int main(){
	return 0;
}