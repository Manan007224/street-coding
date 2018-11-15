#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }

    TreeNode* runner(vector<int> &n, int s, int m, int e){
    	if(s<=e){
    		int mid=s+(e-s)/2;
	    	TreeNode* tp=new TreeNode(n[mid]);
	    	tp->left=runner(n,s,mid-1);
	    	tp->right=runner(n,mid+1,e);
    	}	
    }
};

int main(){
	return 0;
}