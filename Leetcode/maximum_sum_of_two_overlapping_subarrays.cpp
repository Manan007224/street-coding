#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
  	int n = A.size();
  	vector<int> P = { A[0] };
  	for(int i = 1; i < n; i++) P.push_back(A[i] + P[i-1]);
  	int ml = P[L-1], mm = P[M-1], res = P[L+M-1];
    if(L + M == n) return res;
  	for(int i = L + M; i < n; i++) {
  		int before_m = P[i-M] - P[i-M-L];
  		int before_l = P[i-L] - P[i-M-L];
  		ml = max(ml, before_m);
  		mm = max(mm, before_l);
  		res = max({res, ml + P[i] - P[i-M], mm + P[i] - P[i-L]});
  	}
  	return res;    	
  }
};


int main() {
	vector<int> arr = {0,6,5,2,2,5,1,9,4};
	Solution sln;
	cout << sln.maxSumTwoNoOverlap(arr, 1, 2) << endl;
	return 0;
}