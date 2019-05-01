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
  ListNode* oddEvenList(ListNode* head) {
    ListNode *r_even, *r_odd;
    ListNode *odd = new ListNode(0), even = new ListNode(0);
    int i = 0;
    while(head) {
      if(i%2==0) {
        even->next = head;
        even = even->next;
      }
      else {
        odd->next = head;
        odd = odd->next;
      }
    }
    head = head->next;
    i++;  
  }
  even->next = NULL;
  odd->next = r_even->next;
  return r_odd->next;
};

int main() {
	vi T = {2,1,3,5,6,4,7};
	ListNode* l1 = new ListNode(T[0]);
	ListNode* l2 = l1;
	for(int i=1; i<T.size(); i++) {
		l1->next = new ListNode(T[i]);
		l1 = l1->next;
	}
	Solution sln;
	ListNode* res = sln.oddEvenList(l2);
	while(res!=NULL) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}