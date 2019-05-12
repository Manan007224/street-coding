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
  int minDeletionSize(vector<string>& A) {
  	int m = A.size(), n = A[0].size();
  	int res = 1;
  	vector<int> dp(n, 1);
  	for(int i=1; i<n; i++) {
  		for(int j=0; j<i; j++) {
  			bool ok = 1;
  			for(int k=0; k<m; k++) {
  				if(A[k][j] > A[k][i]) {
  					ok = 0;
  					break;
  				}
  			}
  			if(ok){
  				dp[i] = max(dp[i], dp[j]+1);
  				res = max(res, dp[i]);
  			}
  		}
  	}
  	return (n-res);
  }
};

int main() {
	vector<string> arr = {"babca", "bbazb"};
	vector<string> arr1 = {"edcba"};
	vector<string> arr2 = {"ghi","def","abc"};
	Solution sln;
	cout << sln.minDeletionSize(arr1) << endl;
	cout << sln.minDeletionSize(arr2) << endl;
	return 0;
}