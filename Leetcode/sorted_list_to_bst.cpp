#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cr = head;
        vector<int> n;
        while(cr) n.push_back(cr->val), cr=cr->next;
        return go(n,0,n.size()-1);
    }
    
    TreeNode* go(vector<int> &n, int l, int r){
        if(l>r) return NULL;
        int m = (l+r)/2;
        TreeNode* tp = new TreeNode(n[m]);
        tp->left = go(n,l,m-1);
        tp->right = go(n,m+1,r);
        return tp;
    }
};


int main() {
	return 0;
}