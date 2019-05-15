#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  vector<int> pancakeSort(vector<int>& A) {
  	int n = A.size();
  	vector<int> flips;
  	for(int i=0; i<n; i++) {
  		if(cs(A)) return flips;
  		int j = fidx(A, n-i);
  		reverse(A.begin(), A.begin()+j+1);
  		flips.pb(j+1);
  		reverse(A.begin(), A.begin()+n-i);
  		flips.pb(n-i);
  	}
  	return flips;   
  }

  int fidx(vector<int> &A, int j) {
  	int mx = -1, ix = -1;
  	for(int i=0; i<j; i++){
  		if(mx < A[i]) mx = A[i], ix = i;
  	}
  	return ix;
  }

  int cs(vector<int> &A) {
  	for(int i=1; i<A.size(); i++) {
  		if(A[i-1] > A[i]) return 0;
  	}
  	return 1;
  }
};

int main() {
	vector<int> arr = {3,1,4,2};
	Solution sln;
	vector<int> res = sln.pancakeSort(arr);
	for(auto r : res) cout << r << endl;
	return 0;
}