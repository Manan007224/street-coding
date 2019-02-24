#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(head == NULL) return NULL;
  		int a {n};
  		ListNode *fast {head}, *slow {head}, *curr {head}, *remove {};
  		while(a--) {
  			fast = fast->next;
  		}
  		if(fast == NULL) {
  			remove = curr;
  			curr = curr->next;
  		}
  		else {
  			while(fast->next) {
	  			fast = fast->next;
	  			slow = slow->next;
  			}
  			remove = slow->next;
  			slow->next = (n==1) ? NULL : slow->next->next;
  		}     
  		delete remove;
  		return curr;
    }
};

int main() {
	vi T = {1,2,3,4,5};
	ListNode* l1 = new ListNode(T[0]);
	ListNode* l2 = l1;
	for(int i=1; i<T.size(); i++) {
		l1->next = new ListNode(T[i]);
		l1 = l1->next;
	}
	Solution sln;
	ListNode* res = sln.removeNthFromEnd(l2, 5);
	while(res!=NULL) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}