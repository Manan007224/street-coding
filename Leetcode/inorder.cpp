#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
  public:
    vector<int> inorderTraversal(TreeNode* root){
      stack<TreeNode*> st; 
      bool over = false;
      auto current = root;
      vector<int> tr;
      while(!over){
        if(current!=NULL){
          st.push(current);
          current = current->left;
        }
        else if(st.empty())
          over = true;
        else{
          current = st.top();
          tr.push_back(current->val);
          st.pop();
          current = current->right;
        }
      }
     return tr;
    }
};

int main() {
  TreeNode root(0);
  stack<TreeNode*> st;
  auto curr = &root;
  curr->left = new TreeNode(25);
  curr->left->left = new TreeNode(12);
  curr->left->right = new TreeNode(30);
  curr->left->left->left = new TreeNode(6);
  curr->left->left->right = new TreeNode(18);
  curr->left->left->right->left = new TreeNode(14);
  Solution sln;
  vector<int> ds = sln.inorderTraversal(curr->left);
  for(int i=0;i<ds.size();i++) cout << ds[i] << " ";
  cout << endl;
  return 0;
}