#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* n;
};

Node* new_node(int dt){
	Node* tp= new Node;
	tp->val=dt; tp->n=NULL;
	return tp;
}

int add_num(Node* list1, Node* list2, Node* ans){
	if(list1==NULL && list2==NULL)
		return 0;
	Node* temp = new Node;
	ans->n = temp;
	int carry = add_num(list1->n,list2->n,ans->n);
	int f = (list1!=NULL) ? list1->val : 0;
	int s = (list2!=NULL) ? list2->val : 0;
	int add = f+s+carry;
	carry = (add>=10) ? 1: 0;
	temp->val=add%10;
	return carry;
}

void runner(Node* l1, Node* l2){
	Node* tp = new Node;
	int cr = add_num(l1,l2,tp);
	Node* final = tp->n;
	if(carry==1){
		Node* jugaad = new_node(1);
		jugaad->n=final;
		final=jugaad;
	}
	return final;
}

int main(){
	Node* list1 = new_node(1);
	list1->n=new_node(2);
	list1->n->n=new_node(3);
	Node* list2 = new_node(4);
	list2->n=new_node(5);
	list2->n->n=new_node(6);
	int carry=0;
	Node* tp= runner(list1,list2);
	while(tp!=NULL){
		cout<<tp->val<<endl;
		tp=tp->n;
	}
	return 0;
}
