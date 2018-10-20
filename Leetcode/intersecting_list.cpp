#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tp1 = headA;
       ListNode* tp2 = headB;
       ListNode* curr1 = headA;
       ListNode* curr2 = headB;

       while(curr1!=curr2){
       		if(curr1==NULL)
       			curr1 = tp2;
       		else
       			curr1 = curr1->next;
       		if(curr2==NULL)
       			curr2 = tp1;
       		else
       			curr2=curr2->next;
       }

       return curr1; 
    }
};

// int main(){
// 	ListNode tp1(1);
// 	auto l1=&tp1;
// 	l1->next=ListNode(3);
// 	l1->next->next=ListNode(5);
// 	ListNode tp2(2);
// 	auto l2=&tp2;
// 	l2->next=ListNode(4);
// 	ListNode common(7);
// 	auto cmn = &common;
// 	cmn->next=ListNode(8);
// 	cmn->next->next=ListNode(9);
// 	l2->next->next=cmn;

// 	return 0;
// }