#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        bool activate = false;
        while(curr!=NULL || !st.empty()){
        	while(curr!=NULL){
        		st.push(curr);
        		curr = curr->left;
        	}
        	TreeNode* now = st.top();
        	st.pop();
        	if(activate) return now;
        	if(now == p) activate=true;
        	curr = now;
        	curr = curr->right;
        }
        return NULL;
    }
};

int main(){
	TreeNode test(5);
	auto root = &test;
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(1);
	Solution sln;
	TreeNode* ans = sln.inorderSuccessor(root, root->right);
	if(ans==NULL) cout<<"NULL"<<endl;
	else
		cout<<ans->val<<endl;
	return 0;
}