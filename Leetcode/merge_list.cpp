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
       		ListNode *a1=l1;
       		ListNode *a2=l2;
       		while(a1!=NULL&&a2!=NULL){
       			if(a1->val<a2->val){
       				current->next=new ListNode(a1->val);
       				a1=a1->next;
       				current=current->next;
       			}
       			else{
       				current->next=new ListNode(a2->val);
       				a2=a2->next;
       				current=current->next;
       			}
       		}
       		while(a1!=NULL){
       			current->next=new ListNode(a1->val);
       			a1=a1->next;
       			current=current->next;
       		}
       		while(a2!=NULL){
       			current->next=new ListNode(a2->val);
       			a2=a2->next;
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
