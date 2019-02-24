#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ListNode*> vl;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator() (ListNode* l1, ListNode* l2) {return l1->val > l2->val;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if(lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode *res = new ListNode(0);
        ListNode *ans = {res};
        for(auto lt : lists){
        	if(lt) pq.push(lt);
        }
        while(!pq.empty()) {
        	ListNode* cr = pq.top();
        	pq.pop();
        	res->next = cr;
          	res = res->next;
        	cr = cr->next;
        	if(cr) {
        		pq.push(cr);
        	}	
        }
        return ans->next;
    }
};

int main() {
	vvi T = {{1,2,4},{3,4,5},{2,3,6}};
	vl Q;
	for(int i=0; i<T.size(); i++) {
		ListNode *l1 = new ListNode(0);
		ListNode *l2 {l2};
		for(int j=0; j<T[i].size(); j++) {
			l1->next = new ListNode(T[j]);
			l1 = l1->next;
		}
		Q.push_back(l2);
	}
	Solution sln;
	ListNode* res = sln.mergeKLists(Q);
	while(res!=NULL) {
		cout << res->val << endl;
		res = res->next;
	}
	// delete all the lists
	for(auto q: Q) {
		ListNode *cr = q;
		ListNode *rem;
		while(cr) {
			rem = cr;
			cr = cr->next;
			delete rem;
		}
	}
	return 0;
}