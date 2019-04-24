#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

struct node {
	int val;
	int count;
	node* left;
	node* right;
	node(int n) {
		count = 0;
		val = n;
		left = NULL;
		right = NULL;
	}
};

class BST {
public:

	node* root;

	BST(int n) {
		root = new node(n);
	}

	int insert(node* curr, int n) {
		if(curr->val>n) {
			curr->count += 1;
			if(curr->left)
				return insert(curr->left,n);
			else {
				curr->left = new node(n);
				return 0;
			}
		}
		else if(curr->val<n) {
			if(curr->right)
				return 1 + curr->count + insert(curr->right,n);
			else {
				curr->right = new node(n);
				return 1 + curr->count;
			}
		}
	}
};

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    BST tree(nums[nums.size()-1]);
    node* curr = tree.root;
    vector<int> res(nums.size());
    res[nums.size()-1] = 0;
    for(int i=nums.size()-2; i>=0; i--) {
    	res[i] = tree.insert(curr, nums[i]);
    }
    return res; 
  }
};


int main() {
	vector<int> t = {5,2,6,1};
	vector<int> t1 = {30,31,25,14,21,29,15,23};
	Solution sln;
	vector<int> res = sln.countSmaller(t);
	for(auto r: res) cout << r << " ";
	cout << endl;
	return 0;
}