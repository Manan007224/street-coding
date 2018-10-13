#include <bits/stdc++.h>
using namespace std;

struct Node{
	string val;
	Node* l;
	Node* r;
};

Node* newNode(string data){
	Node* tp = new Node;
	tp->val = data;
	tp->l=NULL;
	tp->r=NULL;
}


Node* flatten(Node* curr){
	Node* left = curr->l;
	Node* right = curr->r;
	if(right!=NULL){
		curr->l=right;
		curr->r=NULL;
		curr=flatten(right);
	}
	if(left!=NULL){
		curr->l=left;
		curr->r=NULL;
		curr=flatten(left);
	}
	return curr;
}

void runner(Node** root){
	Node* curr = *root;
	flatten(*root);
}

// void flatten(Node** head){
// 	stack<Node*> st;
// 	Node* tp = *head;
// 	st.push(tp);
// 	while(!st.empty()){
// 		Node* curr = st.top();
// 		st.pop();
// 		if(curr->l!=NULL)
// 			st.push(curr->l);
// 		if(curr->r!=NULL)
// 			st.push(curr->r);
// 		tp->l=curr;
// 		tp->r=NULL;
// 		tp=tp->l;
// 	}
// }

int main(){
	Node* root=newNode("a");
	root->l=newNode("b");
	root->l->l = newNode("c");
	root->l->l->r=newNode("k");
	root->l->l->l=newNode("d");
	root->l->l->l->l=newNode("e");
	root->l->l->l->l->r=newNode("l");
	root->l->r=newNode("f");
	root->l->r->l=newNode("g");
	root->l->r->l->l=newNode("j");
	root->l->r->r=newNode("h");
	root->l->r->r->l=newNode("i");
	Node* ans = root;
	flatten(root);
	while(ans!=NULL){
		cout<<ans->val<<endl;
		ans=ans->l;
	}
	return 0;
}