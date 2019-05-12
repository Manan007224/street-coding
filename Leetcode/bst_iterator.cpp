#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class BSTIterator {
public:

	stack<TreeNode*> st;

  BSTIterator(TreeNode* root) {
    push_left(root);
  }

  int next() {
   	TreeNode *curr = st.top();
   	st.pop();
   	push_left(curr->right);
   	return curr->val;
  }

  bool hasNext() {
    return !(st.empty());
  }

  void push_left(TreeNode *curr) {
  	while(curr) {
  		st.push(curr);
  		curr = curr->left;
  	}
  }
};

int main() {
	return 0;
}