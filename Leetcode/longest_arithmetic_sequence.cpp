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
  int longestArithSeqLength(vector<int>& A) {
  	int n = A.size(), res = 1;
  	if(n==0) return 0;
  	unordered_map<int, unordered_map<int,int>> dp;
  	for(int i=0; i<n; i++) {
  		for(int j=0; j<i; j++){
  			int diff = A[i]-A[j];
  			dp[j][diff] = 1;
  		}
  	}
  	for(int i=1; i<n; i++) {
  		for(int j=0; j<i; j++) {
  			int diff = A[i]-A[j];
				dp[i][diff] = max(dp[i][diff], dp[j][diff]+1);
				res = max(res, dp[i][diff]);
  		}
  	}
  	return res;    
  }
};

int main() {
	vector<int> arr = {20,1,15,3,10,5,8};
	vector<int> arr1 = {20,1,15,13,11,10,9,7,5,3,8};
	vector<int> arr2 = {3,6,9,12};
	vector<int> arr3 = {9,4,7,2,10};
	vector<int> arr4 = {24,13,1,100,0,94,3,0,3};
	vector<int> arr5 = {0,3,0,3};
	Solution sln;
	cout << sln.longestArithSeqLength(arr) << endl;
	cout << sln.longestArithSeqLength(arr1) << endl;
	cout << sln.longestArithSeqLength(arr2) << endl;
	cout << sln.longestArithSeqLength(arr3) << endl;
	cout << sln.longestArithSeqLength(arr4) << endl;
	cout << sln.longestArithSeqLength(arr5) << endl;
	return 0;
}