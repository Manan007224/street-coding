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
  double largestSumOfAverages(vector<int>& A, int K) {
  	int n = A.size();
    vii_32 dp(n, vi_32(K, -1));
    double sum = 0;
    for(int i=0; i<n; i++) {
    	sum += A[i];
    	dp[i][0] = sum/(i+1);
    }
    int res = go(A, 0, K-1, dp);
    return res;    
  }

  double go(vector<int> &arr, int start, int K, vii_32 dp) {
  	int n = arr.size()-1;
  	if(n-start < K)
  		return 0;
  	if(dp[start][K] != -1)
  		return dp[start][K];
  	double sum = 0;
  	double x = INT_MIN;
  	for(int i=start; i<=n; i++) {
  		sum += arr[i];
  		double next_average = go(arr, i+1, K-1, dp);
  		x = max(x, next_average + sum/(i+1));
  	}
  	return dp[start][K] = x;
  }
};

int main() {
	vector<int> arr = {9,1,2,3,9};
	Solution sln;
	cout << sln.largestSumOfAverages(arr, 3) << endl;
	return 0;
}