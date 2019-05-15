#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	
  struct TreePair {
    int depth;
    TreeNode* node;
    TreePair(int d, TreeNode* r) : depth(d), node(r) {};
  };

  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    TreePair res = dfs(root);
    return res.node;
  }

  TreePair dfs(TreeNode* curr) {
    if(!curr) return TreePair(0, NULL);
    TreePair left = dfs(curr->left);
    TreePair right = dfs(curr->right);
    if(left.depth == right.depth) {
      return TreePair(left.depth+1, curr);
    }
    else if(left.depth > right.depth) {
      return TreePair(left.depth+1, left.node);
    }
    else {
      return TreePair(right.depth+1, right.node);
    }
  }
};