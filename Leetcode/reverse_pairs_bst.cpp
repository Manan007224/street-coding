#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	int dups;
	int right_childs;
	node* left;
	node* right;
	node(int n) {
		val = n;
		dups = 0;
		right_childs = 0;
		left = NULL;
		right = NULL;
	}
}

class BST {
public:

	node* root;
	int reverse_pairs;

	BST() {
		root = new node();
		reverse_pairs = 0;
	}

	void insert(node* curr, int n) {
		if(curr->val < n) {
			curr->right_childs += 1;
			if(curr->right)
				insert(curr->right, n);
			else 
				curr->right = new node(n);
		}
		else if(curr->val > n) {
			if(curr->val > 2*n)
				reverse_pairs += (1 + curr->right_childs + curr->dups);
			if(curr->left)
				insert(curr->left, n);
			else
				curr->left = new node(n);
		}
		else 
			curr->dups +=1;
	}
}

class Solution {
public:
  int reversePairs(vector<int>& nums) {
  	BST tree;
  	node* curr = tree.root;
  	tree.insert(curr, nums[0]);
  	for(int i=1; i<nums.size(); i++) {
  		tree.insert(curr, nums[i]);
  	}
  	return tree.reverse_pairs;
  }
};


int main() {
	vector<int> t = {15,2,18,4,13,6,19,27,3};
	Solution sln;
	cout << sln.reversePairs(t) << endl;
	return 0;
}