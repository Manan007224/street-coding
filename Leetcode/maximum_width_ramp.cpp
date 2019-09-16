#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxWidthRamp(vector<int>& A) {
  	int n = A.size(), lo, hi;
    vector<int> st;
    int res = 0;
    for(int i=0; i<n; i++) {
      if(st.size()!=0 && A[st[st.size()-1]]<=A[i]) {
        lo = 0, hi = n-1;
        while(lo < hi) {
          int mid = lo + (hi-lo)/2;
          A[i] < A[st[mid]] ? lo = mid+1 : hi = mid;
        }
        res = max(res, i-st[lo]);  
      }
      else st.push_back(i);  
    }    
  }
};

int main() {
	vector<int> arr = {9,8,13,14,5,7,1,18};
	Solution sln;
	cout << sln.maxWidthRamp(arr) << endl;
	return 0;
}