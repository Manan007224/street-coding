#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int lo = matrix[0][0], hi = matrix[n-1][n-1];
    while(lo < hi) {
    	int mid = lo + (hi-lo)/2;
    	int cnt = 0;
    	// for(int i=0; i<n; i++) {
    	// 	for(int j=0; j<matrix[i].size(); j++) {
    	// 		if(matrix[])
    	// 	}
    	// }
    	for(auto m: matrix) {
    		cnt += upper_bound(m.begin(), m.end(), mid) - m.begin();
    	}
    	cnt < k ? lo = mid+1 : right = mid;
    }
    return right;
  }
};

int main() {
	return 0;
}