#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ListNode {

private: 
	struct Node {
		Node *link;
		int data;
	};
	Node *head;
	Node *tail;
public:
	ListNode() {
		head = NULL; tail = NULL;
	}
	void add_front(int val) {
		Node *fs = new Node();
		if(head == NULL) {
			fs->data = val; fs->link = NULL;
			head = fs; tail = fs;
		}
		else {
			fs->data = val; fs->link = head;
			head = fs;
		}
	}
	void add_back(int val) {
		Node *fs = new Node();
		fs->data = val; fs->link = NULL;
		if(head == NULL){
			head = fs; 
			tail = fs;
		}
		else {
			tail->link = fs;
			tail = tail->link;
		}
	}
	void print() {
		Node * iter;
		for(iter=head;iter!=NULL;iter=iter->link)
			cout << iter->data << " ";
		cout << endl;
	}
};

void Solution(ListNode &tp1, ListNode &tp2) {
	
}

int main() {
	ListNode ll;
	ll.add_front(4); ll.add_back(40); ll.add_back(400);

	return 0;
}