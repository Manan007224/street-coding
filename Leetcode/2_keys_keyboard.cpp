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
  int minSteps(int n) {
  	vector<int> dp(n+1, 0);
  	for(int i=2; i<=n; i++) {
  		dp[i] = 2;
  		for(int j=i-1; j>1; j--) {
  			if(i%j==0) {
  				dp[i] = dp[j] + (i/j);
  				break;
  			}
  			else dp[i]++;
  		}
  	}
    return dp[n];  
  }
};

int main() {
	Solution sln;
	cout << sln.minSteps(9) << endl;
	cout << sln.minSteps(6) << endl;
	cout << sln.minSteps(14) << endl;
	cout << sln.minSteps(7) << endl;
	cout << sln.minSteps(76) << endl;
	return 0;
}