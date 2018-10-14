#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> tree;
		stack<TreeNode*> st;
		TreeNode* curr = root;
		while(curr!=NULL || !st.empty()){
			while(curr!=NULL){
				st.push(curr);
				curr=curr->left;
			}
			TreeNode* now = st.top();
			st.pop();
			tree.push_back(now->val);
			curr = now;
			curr = curr->right;
		}
		return tree;
	}
};

int main(){
	TreeNode test(1);
	auto root = &test;
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	Solution sln;
	vector<int> tree;
	tree = sln.inorderTraversal(root);
	for(auto t: tree)
		cout<<t<<endl;
	return 0;
}