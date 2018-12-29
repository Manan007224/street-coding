//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<TreeNode*,TreeNode*> TreeMap;
typedef queue<TreeNode*> TreeQueue;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeMap parent;
        TreeQueue q;
        q.push(root);
        while(!q.empty()){
            TreeNode* now=q.front(); q.pop();
            if(now->left){
                parent.insert({now->left,now});
                q.push(now->left);
            }
            if(now->right){
                parent.insert({now->right,now});
                q.push(now->right);
            }
        }
        auto lcap=parent.find(p).second;
        auto lcaq=parent.find(q).second;
        while(lcap!=lcaq){
            lcap=parent.find(lcap).second;
            lcaq=parent.find(lcaq).second;
        }
        return lcap;
    }
};

int main(){
    return 0;
}