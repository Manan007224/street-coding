#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node* next;
	node(int x): val(x), next(NULL) {}
};

int main(){
	node* l1 = new node(5);
	l1->next=new node(6);
	cout<<l1->next->val<<endl;
	return 0;
}