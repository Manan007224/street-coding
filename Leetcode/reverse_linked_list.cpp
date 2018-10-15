#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode *reverseList(ListNode *head){
		ListNode * curr = head;
		ListNode * prev = NULL;
		ListNode * after = NULL;
		while(curr!=NULL){
			after=curr->next;
			curr->next=prev;
			prev=curr;
			curr=after;
		}
		head=prev;
		return head;
	}
};

int main(){
	ListNode tp1(1);
	auto reverse=&tp1;
	reverse->next=new ListNode(2);
	reverse->next->next=new ListNode(3);
	Solution sln;
	ListNode * curr1=reverse;
	ListNode * ans= sln.reverseList(reverse);
	ListNode * curr=ans;
	while(curr!=NULL){
		cout<<curr->val<<endl;
		curr=curr->next;
	}
	return 0;
}