#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {      
        ListNode* ff=head;
        ListNode* fs=head;
        if(!ff||!ff->next) return false;      
        while(ff->next&&fs->next){
        	if(ff=fs) return true;
        	fs=fs->next;
        	ff=ff->next;
        	ff=(ff->next!=NULL) ? ff->next: ff;
        }
        return false;
    }
};

int main(){
	return 0;
}