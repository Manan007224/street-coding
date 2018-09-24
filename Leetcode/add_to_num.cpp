#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};

ListNode* new_node(int val){
	ListNode *l1 = new ListNode;
	l1->val = val;
	l1->next = NULL;
	return l1;
}


class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode * current = new_node(0);
			int cr = 0;
			while(l1!=NULL || l2!=NULL) {	
				int f = l1!=NULL ? l1->val : 0;
				int s = l2!=NULL ? l2->val : 0;
				int add = (f+s+cr);
				cr = add/10;
				cout << add%10 << endl;
				current->next = new_node(add%10);	
				l1 = l1 ? l1->next : NULL;
				l2 = l2 ? l2->next : NULL;
				current = current->next;
			}
			if(cr>0) 
				current->next = new_node(cr);
			return current->next;
		}
		
};

int main(){
	Solution sln;
	ListNode * l1 = new_node(1); l1->next = new_node(3);
	ListNode * l2 = new_node(2); l2->next = new_node(4);
	ListNode * l3 = sln.addTwoNumbers(l1,l2);
	ListNode * iter;

	for(iter=l3;iter!=NULL;iter=iter->next)
		cout << iter->val << endl;

	return 0;
}	