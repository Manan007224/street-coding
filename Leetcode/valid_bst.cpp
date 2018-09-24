#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	return isValidBSTr(root, numeric_limits<long>::min(), numeric_limits<long>::max());
        // if(root==NULL)
        // 	return true;
        // cout << "Value = " << root->val << " " << endl;
       	// if(root->left!=NULL && root->val<root->left->val)
       	// 	return false;
       	// if(root->right!=NULL && root->val>root->right->val)
       	// 	return false;
        // return (isValidBST(root->left)&&isValidBST(root->right));
    }

    bool isValidBSTr(TreeNode* root, long mn, long mx){
    	if(root==NULL)
    		return true;
    	if(!(root->val>mn && root->val<mx))
    		return false;
    	return (isValidBSTr(root->left, mn, root->val) && isValidBSTr(root->right, root->val, mx));
    }
};

int main(){
	TreeNode root(0);
	auto curr = &root;
	curr->left = new TreeNode(2);
	curr->left->left = new TreeNode(1);
	curr->left->right = new TreeNode(3);
	// curr->left->left->left = new TreeNode(2);
	// curr->left->left->right = new TreeNode(4);
	Solution sln;
	if(sln.isValidBST(curr->left))
		cout << "True";
	else 
		cout << "False";
	return 0;
}