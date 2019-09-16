#include <bits/stdc++.h>
using namespace std;

strcut TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  	res = vector<TreeNode*>{};
    for(auto t:to_delete) del.insert(t);

  }

  void traverse(TreeNode* curr) {
    if(curr==NULL) return;
    if(del.find(curr->val)!=del.end()) {
    	curr->val
    }
  }

private:
	vector<TreeNode*> res;
	unordered_set<int> del;
};