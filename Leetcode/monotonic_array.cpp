#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int>& A) {
    int n = A.size();
    bool inc = 1, dec = 1;
    for(int i=0; i<n-1; i++) {
      if(A[i] > A[i+1]) inc = 0;
      if(A[i] < A[i+1]) dec = 0;
    }
    return (inc || dec);
  }
};