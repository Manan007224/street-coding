#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(preorder.size()==0 || inorder.size()==0) return NULL;
  		return recur(preorder, inorder);      
    }

    TreeNode* recur(vi& pr, vi& ir){
    	int lp=pr.size(), lr=ir.size();
    	int root{pr[0]}, pos{-1};
    	pr.erase(pr.begin());
    	for(int i=0;i<lr;i++){
    		if(ir[i]==root) {pos=i; break;}
    	}
    	vector<int> lt, rt;
    	for(int i=0;i<pos;i++) lt.push_back(ir[i]);
    	for(int i=pos+1;i<lr;i++) rt.push_back(ir[i]);
    	TreeNode* now = new TreeNode(root);
    	if(!lt.size()==0) now->left = recur(pr, lt);
    	if(!rt.size()==0) now->right = recur(pr, rt);
    	return now;
    }
};

vi bfs_check(TreeNode* root){
    	queue<TreeNode*> q;
    	vi tree;
    	q.push(root);
    	tree.push_back(root->val);
    	while(!q.empty()){
    		TreeNode* now = q.front(); q.pop();
    		if(now->left) {q.push(now->left); tree.push_back(now->left->val);}
    		if(now->right) {q.push(now->right); tree.push_back(now->right->val);}
    	}
    	return tree;
    }

int main(){
	Solution sln;
	vi pr = {1,2,4,8,9,5,3,6,7,10,11};
	vi ir = {8,4,9,2,5,1,6,3,10,7,11};
	vi pr1 = {3,9,20,15,7};
	vi ir1 = {9,3,15,20,7};
	TreeNode* ans = sln.buildTree(pr, ir);
	vi tree = bfs_check(ans);
	for(auto& t: tree) cout<<t<<endl;
	return 0;
}