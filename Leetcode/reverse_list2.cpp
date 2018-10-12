#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* tp = head;
        myReverse(&tp,2,4);
        return tp;
    }
    void myReverse(ListNode **head, int m, int n){
    	int rr = 0;
    	ListNode* temp = *head;
    	while(rr++<m-2)
    		temp=temp->next;
    	int rm=m;
    	ListNode* prev = temp->next;
    	ListNode* after = temp->next;
    	ListNode* curr = temp->next->next;
    	while(rm++<n){
    		after=curr->next;
    		curr->next=prev;
    		prev=curr;
    		curr=after;
    	}
    	temp->next->next=after;
    	temp->next=prev;
    }	
};

int main(){
	ListNode tp1(1);
	auto reverse=&tp1;
	reverse->next=new ListNode(2);
	reverse->next->next=new ListNode(3);
	reverse->next->next->next=new ListNode(4);
	reverse->next->next->next->next=new ListNode(5);
	Solution sln;
	ListNode* ans = sln.reverseBetween(reverse, 2, 4);
	while(ans!=NULL){
		cout<<ans->val<<endl;
		ans=ans->next;
	}
	return 0;
}