#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    TreeNode* recur(vector<int> &nums, int left, int right){
        if(left<right)
            return NULL;
        int mid = (left+right)/2;
        TreeNode* tp = new TreeNode(nums[mid]);
        tp->left = recur(nums, left, mid-1);
        tp->right = recur(nums, mid+1, left);
        return tp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return(recur(nums,0,nums.size()-1));
    }
};

int main(){
	return 0;
}