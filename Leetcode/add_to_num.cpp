#include <iostream>
using namespace std;

// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode temp(0);
			auto current = &temp;
			int cr = 0;
			while(l1!=NULL || l2!=NULL) {	
				int f = l1!=NULL ? l1->val : 0;
				int s = l2!=NULL ? l2->val : 0;
				int add = (f+s+cr);
				cr = add/10;
				cout << add%10 << endl;
				current->next = new ListNode(add%10);	
				l1 = l1 ? l1->next : NULL;
				l2 = l2 ? l2->next : NULL;
				current = current->next;
			}
			if(cr>0) 
				current->next = new ListNode(cr);
			return temp.next;
		}
		
};
