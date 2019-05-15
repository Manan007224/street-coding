#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    return check(root1, root2);
  }

  bool check(TreeNode* r1, TreeNode* r2) {
    if(!r1 && !r2) return 1;
    if(!r1 || !r2) return 0;
    if(r1->val != r2->val) return 0;
    bool c1 = (check(r1->left, r2->left) && check(r1->right, r2->right));
    bool c2 = (check(r1->left, r2->right) && check(r1->right, r2->left));
    return c1 || c2;
  }
};