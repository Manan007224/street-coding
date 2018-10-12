#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
        	return NULL;
        else if(l1==NULL && l2!=NULL)
        	return l2;
        else if(l2!=NULL && l2==NULL)
        	return l1;
        else{
        	ListNode tp(0);
        	auto current = &tp;
       		while(l1!=NULL&&l2!=NULL){
       			if(l1->val<=l2->val){
       				current->next=l1;
       				l1=l1->next;
       				current=current->next;
       			}
       			else{
       				current->next=l2;
       				l2=l2->next;
       				current=current->next;
       			}
       		}
       		while(l1!=NULL){
       			current->next=new ListNode(l1->val);
       			l1=l1->next;
       			current=current->next;
       		}
       		while(l2!=NULL){
       			current->next=new ListNode(l2->val);
       			l2=l2->next;
       			current=current->next;
       		}
       		return tp.next;
        }
    }
};

int main(){
		ListNode tp1(2);
		auto l1=&tp1;
		l1->next=new ListNode(4);
		l1->next->next=new ListNode(9);
		ListNode tp2(5);
		auto l2=&tp2;
		l2->next=new ListNode(6);
		l2->next->next=new ListNode(7);
		Solution sln;
		ListNode *ans=sln.mergeTwoLists(l1,l2);
		ListNode *curr=ans;
		while(curr!=NULL){
			cout<<curr->val<<endl;
			curr=curr->next;
		}
		return 0;
}
