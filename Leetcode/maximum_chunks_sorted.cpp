#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
  	int mx = 0, chunks = 0;
  	int n = arr.length();
  	for(int i=0; i<n; ++i) {
  		mx = max(mx, arr[i]);
  		if(mx == i) ++chunks;
  	}    
  }
};

int main() {
	return 0;
}