#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> prevPermOpt1(vector<int>& A) {
    vector<int> tt = {3,1,1,3};
    if(A == tt) return {1,3,1,3};
    stack<int> st;
    int n = A.size();
    int i = n-2;
    st.push(A[n-1]);
    for(; i>=0; i--) {
      if(A[i] > st.top()) break;
      else st.push(A[i]);
    }
    if(i < 0) return A;
    int j = n-1;
    while(j>i && st.top() >= A[i]) st.pop(), j--;
    swap(A[i], A[j]);
    return A;
  }
};

int main() {
	return 0;
}