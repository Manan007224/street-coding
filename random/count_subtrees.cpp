#include <bits/stdc++.h>
using namespace std;

typedef map<int,int> mp;
typedef vector<bool> lst_b;

struct node{
	int v;
	node* l;
	node* r;
};

node* new_node(int data){
	node* tp = new node();
	tp->v=data; tp->l=NULL; tp->r=NULL;
}

int bfs(node* root, int target){
	queue<node*> q;
	lst_b v(100,false);
	q.push(root);
	v[root->v]=true;
	int ans=0;
	while(!q.empty()){
		int local_sum = 0;
		node* curr = q.front();
		q.pop();
		local_sum+=curr->v;
		if(curr->l!=NULL && !v[curr->l->v]){
			q.push(curr->l);
			v[curr->l->v]=true;
			local_sum+=curr->l->v;
		}
		if(curr->r!=NULL && !v[curr->r->v]){
			q.push(curr->r);
			v[curr->r->v]=true;
			local_sum+=curr->r->v;
		}
		if(local_sum==target) ans++;
	}
	return ans;	
}

int main(){
	node* root=new_node(5);
	root->l=new_node(9);
	root->r=new_node(3);
	root->l->l=new_node(11);
	root->l->r=new_node(8);
	root->r->l=new_node(4);
	root->r->r=new_node(17);
	int ans=bfs(root,17);
	cout<<ans<<endl;
	return 0;
}