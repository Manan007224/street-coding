#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x){
  		ListNode tp1{0}; auto l1=&tp1;
  		ListNode tp2{0}; auto l2=&tp2;
  		ListNode* cr=head;
  		while(head){
  			if(head->val<x){
  				l1->next=head; l1=l1->next;
  			} else{
  				l2->next=head; l2=l2->next;
  			}
  			head=head->next;
  		}
  		l1->next=tp2.next;
  		l2->next=NULL;
  		return tp1.next;
    } 
};