#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree {
public:
	vi arr;

	SegmentTree(int n) {
		int x;
		if(n!=0 && (n & (n-1)) == 0) x = n;
		else {
			while(x<=n) x = x<<1;
		}
		arr.assign(x*2-1,INT_MAX);
	}

	void create(vi &tree) {
		create_helper(tree,0,tree.size()-1,0);
	}

	void create_helper(vi &tree, int lo, int hi, int pos) {
		if(lo==hi) {
			arr[pos] = tree[lo];
			return;
		}
		int mid = (lo+hi)/2;
		create_helper(tree,lo,mid,2*pos+1);
		create_helper(tree,mid+1,hi,2*pos+2);
		arr[pos] = min(arr[2*pos+1],arr[2*pos+2]);
	}

	int range_min(int qlo, int qhi) {
		return range_min_helper(qlo, qhi, 0, arr.size()-1, 0);
	}

	int range_min_helper(int qlo, int qhi, int lo, int hi, int pos) {
		if(qlo <= lo && qhi >= hi) return arr[pos]; // total overlap
		if(qlo > hi || qhi < lo) return INT_MAX; // no overlap
		int mid = (lo+hi)/2;
		int left = range_min_helper(qlo, qhi, lo, mid, pos*2+1);
		int right = range_min_helper(qlo, qhi, mid+1, hi, pos*2+2);
		return min(left,right);
	}
};

int main() {
	vi t = {-1,2,4,0};
	SegmentTree test(t.size());
	test.create(t);
	for(auto a: test.arr) cout << a << " ";
	cout<<endl;
	cout<<test.range_min(1,3)<<endl;
	cout<<test.range_min(1,2)<<endl;
	cout<<test.range_min(0,2)<<endl;
	return 0;
}