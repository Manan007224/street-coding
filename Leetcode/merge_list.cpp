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
    ListNode *result = new node(0);
    if(l1 == NULL && l2 == NULL) return result->next;
    ListNode *curr = result->next;
    while(l1 && l2) {
      if(l1->val <= l2->val) {
        curr->next = l1->val;
        curr = curr->next;
        l1 = l1->next;
      }
      else {
        curr->next = l2->val;
        curr = curr->next;
        l2 = l2->next;
      }
    }
    (l1) ? curr->next = l1 : curr->next = l2;
    return result->next;
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
