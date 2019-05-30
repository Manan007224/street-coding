#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lastRemaining(int n) {
  	int i = 1, j = n;
  	int num_gap = 1;
  	bool turn = 1; // true for start and 0 for end
  	while(i < j) {
  		if(turn) {
  			i += num_gap;
  			if(n%2 != 0) j -= num_gap;
  		}
  		else {
  			j -= num_gap;
  			if(n%2 != 0) i += num_gap;
  		}
  		n /= 2, num_gap *= 2;
  		turn = !(turn);
  		// cout << i << "  " << j << endl;
  	}
  	return i;
  }
};


int main() {
	int n = 17;
	Solution sln;
	cout << sln.lastRemaining(17) << endl;
	return 0;
}