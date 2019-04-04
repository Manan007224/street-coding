#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Segmentinput {
public:
	vi tree, lazy;

	Segmentinput(int n) {
		int x;
		if(n!=0 && (n & (n-1)) == 0) x = n;
		else {
			while(x<=n) x = x<<1;
		}
		tree.assign(x*2-1,INT_MAX);
		lazy.assign(x*2-1,0);
	}

	void create(vi &input) {
		create_helper(input,0,input.size()-1,0);
	}

	void create_helper(vi &input, int lo, int hi, int pos) {
		if(lo==hi) {
			tree[pos] = input[lo];
			return;
		}
		int mid = (lo+hi)/2;
		create_helper(input,lo,mid,2*pos+1);
		create_helper(input,mid+1,hi,2*pos+2);
		tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
	}

	int range_min(int qlo, int qhi) {
		return rm_helper(qlo, qhi, 0, tree.size()-1, 0);
	}

	int rm_helper(int qlo, int qhi, int lo, int hi, int pos) {
		if(qlo <= lo && qhi >= hi) return tree[pos]; // total overlap
		if(qlo > hi || qhi < lo) return INT_MAX; // no overlap
		int mid = (lo+hi)/2;
		int left = rm_helper(qlo, qhi, lo, mid, pos*2+1);
		int right = rm_helper(qlo, qhi, mid+1, hi, pos*2+2);
		return min(left,right);
	}

	int range_min_lazy(int qlo, int qhi, int size) {
		return rml_helper(qlo, qhi, 0, size, 0);
	}

	int rml_helper(int qlo, int qhi, int lo, int hi, int pos) {
		if(lo > hi) return INT_MAX;

		// If we haven't done propogation at this time
		if(lazy[pos]!=0) {
			tree[pos] += lazy[pos];
			if(lo != hi) {
				lazy[pos*2+1] += lazy[pos];
				lazy[pos*2+2] += lazy[pos];
			}
			lazy[pos] = 0; 
		}

		if(qlo > hi || qhi < lo) return INT_MAX; // no overlap
		if(qlo <= lo && qhi >= hi) return tree[pos]; // total overlap
		int mid = (lo+hi)/2;
		int left = rml_helper(qlo, qhi, lo, mid, pos*2+1);
		int right = rml_helper(qlo, qhi, mid+1, hi, pos*2+2);
		return min(left,right);
	}

	void update_lazy(int qlo, int qhi, int diff, int size) {
		ul_helper(qlo, qhi, diff, 0, size, 0);
	}

	void ul_helper(int qlo, int qhi, int diff, int lo, int hi, int pos) {
		if(lo > hi) return;
		
		// If we haven't done the propogation at this point
		if(lazy[pos]!=0) {
			tree[pos] += lazy[pos];
			if(lo != hi) {
				lazy[pos*2+1] += lazy[pos];
				lazy[pos*2+2] += lazy[pos];
			}
			lazy[pos] = 0;
		}

		if(qlo > hi || qhi < lo) return; // no overlap 

		// total overlap
		if(qlo <= lo && qhi >= hi) {
			tree[pos] += diff;			
			if(lo != hi) {
				lazy[2*pos+1] += diff;
				lazy[2*pos+2] += diff;
			}
			return;
		}

		// partial overlap
		int mid = (lo+hi)/2;
		ul_helper(qhi, qlo, diff, lo, mid, pos*2+1);
		ul_helper(qhi, qlo, diff, mid+1, hi, pos*2+2);
		tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
	}
};

int main() {
	vi t = {-1,2,4,0};
	vi t1 = {2,3,-1,4};
	Segmentinput test(t.size());
	Segmentinput test1(t1.size());
	test.create(t);
	test1.create(t1);
	cout<<test.range_min(1,3)<<endl;
	cout<<test.range_min(1,2)<<endl;
	cout<<test.range_min(0,2)<<endl;
	test1.update_lazy(0,3,2,3);
	test1.update_lazy(2,2,4,3);
	cout<<test1.range_min_lazy(1,2,3)<<endl;
	return 0;
}