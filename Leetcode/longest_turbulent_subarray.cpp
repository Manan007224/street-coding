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
  int maxTurbulenceSize(vector<int>& A) {
  	int last = 0, res = 1, n = A.size();
  	for(int i=1; i<n; i++) {
  		if(A[i]==A[i-1]) {
  			res = max(res, i-last);
  			last = i;
  		}
  		else if(i==n-1 || (!((A[i-1]<A[i] && A[i]>A[i+1]) || (A[i-1]>A[i] && A[i]<A[i+1])))) {
  			res = max(res, i-last+1);
  			last = i;
  		}
  	}
  	return res;    
  }
};

int main() {
	vector<int> arr = {9,4,2,10,7,8,8,1,9};
	vector<int> arr1 = {4,8,12,16};
	vector<int> arr2 = {100};
	vector<int> arr3 = {0,8,45,88,48,68,28,55,17,24};
	vector<int> arr4 = {9,9,9,9};
	Solution sln;
	cout << sln.maxTurbulenceSize(arr3) << endl;
	return 0;
}