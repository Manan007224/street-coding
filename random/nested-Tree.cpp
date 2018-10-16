#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
};

Node * addNode(int data) {
	Node *n = new Node();
	n->val = data; n->left = nullptr; n->right = nullptr;
	return n;
}

bool isBalanced(Node *root) {
	if(root != nullptr) {
		queue<Node> q;
		q.push(root);
		while(!q.isEmpty()) {
			Node *t = q.front(); q.pop();
			int diff = getHeight(t->left) - getHeight(t->right);
			if(diff < -1 || diff > 1) return false;
		}
	return true;
	}
}

int getHeight(Node *root) {
	queue<Node> q;
	int h=0;
	int curr = 1; int n = 0;
	while(!temp.isEmpty()) {
		Node *c = q.front(); q.pop();
		curr --;
		if(temp->left!=nullptr) {
			q.push(temp->left); curr--;
		}
		if(temp->right!=nullptr) {
			q.push(temp->right); curr--;
		}
		if (current == 0) {
			h++;
			current = next;
			next = 0;
		}
		return h-1;
	}
}

int main() {
	Node *root = addNode(5);
	root->left = addNode(10);
	root->right = addNode(15);
	cout << root->left->val << " " << root->right->val << endl;
	return 0;
}