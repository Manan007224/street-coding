#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left, *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }

class Solution {
public:
  int mxp = INT_MIN;
  
  int maxPathSum(TreeNode* root) {
   go(root);
   return mxp; 
  }
  int go(TreeNode* curr) {
    if(curr==NULL) return 0;
    int left = max(go(curr->left),0);
    int right = max(go(curr->right),0);
    mxp = max(mxp,left+right+curr->val);
    return curr->val+max(left,right);
  }
};

int main() {
	return 0;
}