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
    vii_32 dp(n+1, vi_32(K+1, 0.0));
    vector<int> prefix(n+1, 0);
    for(int i=0; i<n; i++) prefix[i+1] = prefix[i]+A[i];
    for(int i=1; i<=n; i++) dp[i][1] = prefix[i]/i;
    if(K<=1) return dp[n][1];
    if(K>=n) return prefix[n]; 
    for(int k=2; k<=K; k++) {
    	for(int i=k; i<=n; i++) {
    		for(int j=i-1; j>=k-1; j--) {
    			double next_average = (prefix[i]-prefix[j])/(i-j);
    			dp[i][k] = max(dp[i][k], dp[j][k-1] + next_average);
    		}
    	}
    }
   return dp[n][K];   
  }
};

int main() {
	vector<int> arr = {9,1,2,3,9};
	Solution sln;
	cout << sln.largestSumOfAverages(arr, 3) << endl;
	return 0;
}