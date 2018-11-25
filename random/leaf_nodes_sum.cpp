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

int bfs(node* root){
	queue<node*> q;
	lst_b v(10,false);
	mp lvl;
	q.push(root);
	lvl[root->v]=0;
	v[root->v]=true;
	int ans=0;
	int mn;
	bool flag=false;
	while(!q.empty()){
		node* curr = q.front();
		q.pop();
		if(curr->l==NULL&&curr->r==NULL && !flag){
			mn = lvl[curr->v];
			ans+=curr->v;
			flag=true;
		}
		else if(curr->l==NULL && curr->r==NULL && flag){
			if(lvl[curr->v]==mn)
				ans+=curr->v;
		}
		if(curr->l!=NULL && !v[curr->l->v]){
			q.push(curr->l);
			lvl[curr->l->v] = 1+lvl[curr->v];
			v[curr->l->v]=true;
		}
		if(curr->r!=NULL && !v[curr->r->v]){
			q.push(curr->r);
			lvl[curr->r->v] = 1+lvl[curr->v];
			v[curr->r->v]=true;
		}
	}
	//for(auto it: lvl) cout<<it.first<<" "<<it.second<<endl;
	return ans;	
}

int main(){
	node* root=new_node(1);
	root->l=new_node(2);
	root->r=new_node(3);
	root->l->l=new_node(4);
	root->l->r=new_node(5);
	root->l->l->l=new_node(7);
	root->l->l->r=new_node(2);
	root->r->r=new_node(8);
	int ans=bfs(root);
	cout<<ans<<endl;
	return 0;
}