#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class BIT {
public:
	vi arr;

	BIT(int n){
		arr.assign(n+1,0);
	}

	void update(int val, int idx) {
		while(idx < arr.size()) {
			arr[idx] += val;
			idx = get_next(idx);
		}
	}

	void create(vi &input) {
		for(int i=1; i<=input.size(); i++){
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
	vector<int> arr = {1,2,3,4,5,6,7};
	BIT tree(7);
	tree.create(arr);
	for(int i = 0; i < 7; i++) cout << tree.sum(i) << endl;
	vector<int> arr1 = {1, 3,5};
	BIT t(3);
	t.create(arr1);
	for(int i = 0; i < 3; i++) cout << t.sum(i) << endl;
	t.update(1, -1);
	cout <<t.sum(2) << endl; 
	return 0;
}