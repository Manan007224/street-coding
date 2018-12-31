// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> TreePair;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        string tree="";
        int cl{1}, nl{0};
        queue<TreeNode*> q;
        q.push(root);
        tree+=to_string(root->val);
        while(!q.empty()){
   			TreeNode* now=q.front();
   			q.pop();
        	cl--;
        	if(now->left!=NULL){
        		nl++;
        		q.push(now->left);
        		tree=tree+","+to_string(now->left->val);
        	}
        	else tree=tree+","+"null";
        	if(now->right!=NULL){
        		nl++;
        		q.push(now->right);
        		tree=tree+","+to_string(now->right->val);
        	}
        	else tree=tree+","+"null";
        	if(cl==0) swap(cl,nl); 
        }
        return tree;
    }

    TreeNode* deserialize(string data) {
    	vector<string> v;
    	string tk;
    	stringstream ts(s);
    	while(getline(ts,tk,',')) v.push_back(tk);
    	TreeNode* root = new TreeNode(stoi(v[0]));
    	TreeNode* ans = root;
    	q.push({root,0});
    	queue<TreePair> q;
    	while(!q.empty()){
    		auto tp = q.front(); q.pop();
    		TreeNode* now = tp.first;
    		int lc {tp.second*2+1}, rc{tp.second*2+2};
    		if(lc<v.size() && v[lc]!="null"){
    			now->left = new TreeNode(stoi(v[lc]));
    			q.push({now->left,lc});
    		}
    		if(rc<v.size() && v[rc]!="null"){
    			now->right = new TreeNode(stoi(v[rc]));
    			q.push({now->right,rc});
    		}
    	}
    	return ans; 
    }
};

int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->left->left=new TreeNode(7);
	Codec sln;
	cout<<sln.serialize(root)<<endl;
	return 0;
}