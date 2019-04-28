#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tpl;

// Path compression and rank based union find

class DisjointSet {
public:

	struct node {
		int val;
		node* parent;
		int rank;
	};

	unordered_map<int, node*> rec;

	void create(int x) {
		node* curr = new node();
		curr->val = x;
		curr->rank = 0;
		curr->parent = curr;
		rec.insert({x, curr});
	}

	void join(int x, int y) {
		node* p1 = find_parent(rec[x]);
		node* p2 = find_parent(rec[y]);

		if(p1->val == p2->val)
			return;

		if(p1->rank >= p2->rank) {
			// only increament the rank of p1 if it's rank is same as of p2->rank
			p1->rank = (p1->rank == p2->rank) ? p1->rank+1 : p1->rank;
			p2->parent = p1;
		}
		else
			p1->parent = p2;
	}

	int find_set(int x) {
		node* res = find_parent(rec[x]);
		return res->val;
	}

	node* find_parent(node* curr) {
		if(curr == curr->parent)
			return curr->parent;
		curr->parent = find_parent(curr->parent);
		return curr->parent;
	}
};

int main() {
	DisjointSet djs;
	for(int i=1; i<=7; i++) djs.create(i);
	djs.join(1,2);
	djs.join(2,3);
	djs.join(4,5);
	djs.join(6,7);
	djs.join(5,6);
	djs.join(3,7);
	for(int i=1; i<=7; i++) cout << djs.find_set(i) << endl;
	return 0;
}