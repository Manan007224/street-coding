#include <bits/stdc++.h>
using namespace std;

struct node{int val; node* left; node* right;};

node* new_node(int val){
	node* tp=new node();
	tp->left=NULL; tp->val=val; tp->right=NULL;
	return tp;
}

void bfs(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* cc=q.front();
		cout<<cc->val<<endl;
		q.pop();
		if(cc->left) q.push(cc->left);
		if(cc->right) q.push(cc->right);
	}
}


int main(){
	node* start=new_node(11);
	start->left=new_node(4);
	start->right=new_node(5);
	start->left->left=new_node(6);
	start->left->right=new_node(7);
	start->right->left=new_node(8);
	start->right->right=new_node(9);
	bfs(start);
	return 0;
}