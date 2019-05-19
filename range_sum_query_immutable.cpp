#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second


struct BIT {
	vector<int> arr;
  
  BIT() {}
  
	BIT (int n) {
		arr = vector<int>(n+1, 0);
	}

	void create(vector<int> val) {
		for(int i = 1; i <= val.size(); i++) { 
			update(i, val[i-1]);
		}
	}

	void update(int i, int val) {
		for(int x = i; x < arr.size(); x += (x & -x)) {
			arr[x] += val;
		}
	}

	int sum(int i) {
		int res = 0;
		for(int x = i + 1; x > 0; x -= (x & -x)) {
			res += arr[x];
		}
		return res;
	}
};

class NumArray {
public:
  NumArray(vector<int>& nums) {
	  tree = BIT(nums.size());
	  tree.create(nums);
    values = nums;
  }
  
  void update(int i, int val) {
    tree.update(i + 1, val-values[i]);
    values[i] = val;
  }
  
  int sumRange(int i, int j) {
    return tree.sum(j) - tree.sum(i-1);  
  }
private:
  BIT tree;
  vector<int> values;
};

int main() {
	vector<int> test = {1,2,3,4,5,6,7};
	NumArray nmr(test);
	nmr.update(4, 13);
	cout << nmr.sumRange(0, 6) << endl;
	return 0;
}