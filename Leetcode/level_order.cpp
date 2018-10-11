#include <bits/stdc++.h>
using namespace std;

struct Node{ 
    struct Node *left; 
    int data; 
    struct Node *right; 
}; 

Node* newNode(int d){
	Node* tp = new Node;
	tp->data = d; tp->left = NULL; tp->right = NULL;
	return tp;
}

void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	cout<<root->data<<endl;
	int next = 0;
	if(root->left!=NULL){
		q.push(root->left);
		next++;
	}
	if(root->right!=NULL){
		q.push(root->right);
		next++;
	}
	q.pop();
	int curr = next;
	while(1){
		if(next==0) break;
		next=0;
		while(curr>0){
			Node * pp = q.front();
			cout<<pp->data<<" ";
			q.pop();
			if(pp->left!=NULL){
				q.push(pp->left);
				next++;
			}
			if(pp->right!=NULL){
				q.push(pp->right);
				next++;
			}	
			curr--;
		}
		cout<<endl;
		curr=next;
	}
}

int main(){
	Node* root = newNode(1);
	root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
    BFS(root); 	
	return 0;
}
