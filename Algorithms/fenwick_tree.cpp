#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class BIT {
public:
	vi arr;

	BIT(int n){
		arr.assign(n,0);
	}

	void update(int val, int idx) {
		while(idx < arr.size()) {
			arr[idx] += val;
			idx = get_next(idx);
		}
	}

	void create(vi &input) {
		for(int i=1; i<arr.size(); i++){
			update(input[i-1],i);
		}
	}

	int sum(int idx) {
		idx = idx+1;
		int sum = 0;
		while(idx > 0) {
			sum += arr[idx];
			idx = get_parent(idx);
		}
		return sum;
	}

	int get_next(int idx) {return idx + (idx & -idx);}
	int get_parent(int idx) {return idx - (idx & -idx);}
};

int main() {
	vi input = {1,2,3,4,5,6,7};
	vi input1 = {3,2,-1,6,5,4,-3,3,7,2,3};
	BIT test(input1.size()+1);
	test.create(input1);
	for(auto x: test.arr) cout<<x<<" ";
	cout<<endl;
	cout<<test.sum(3)<<endl;
	return 0;
}