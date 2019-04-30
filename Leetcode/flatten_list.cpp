#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *right, *down;
	Node(int x): val(x), right(NULL), down(NULL) {} 
};

Node* flatten(Node *curr) {
	Node *right = curr->right, *down = curr->down;
	if(down) {
		curr->right = down;
		curr->down = NULL;
		curr = flatten(curr->right);

	}
	if(right) {
		curr->right = right;
		curr->down = NULL;
		curr = flatten(curr->right);
	}
	return curr;
}

int main() {
	Node *root = new Node(1);
	root->down = new Node(2);
	root->down->down = new Node(3);
	root->down->down->right = new Node(4);
	root->down->down->right->right = new Node(5);
	root->right = new Node(6);
	root->right->right = new Node(7);
	root->right->right->down = new Node(8);
	root->right->right->down->right = new Node(9);
	root->right->right->right = new Node(10);
	root->right->right->right->right = new Node(11);
	root->right->right->right->right->down = new Node(12);
	Node *ans = root;
	flatten(root);
	while(ans!=NULL) {
		cout << ans->val << endl;
		ans = ans->right;
	}
	return 0;
}	