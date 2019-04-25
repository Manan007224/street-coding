#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second


int main() {
	int n; cin >> n;
	vector<bool> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	int sum; cin >> sum;
	vector<vector<bool>> dp(sum+1, vector<bool>(n+1,0));
	vector<vector<int>> count(sum+1, vector<int>(n+1,0));
	for(int i=0; i<=sum; i++){
		dp[i][0] = 0;
		count[i][0] = -1;
	}
	for(int i=0; i<=n; i++){
		dp[0][i] = 1;
		count[0][i] = 0;
	}
	for(int i=1; i<=sum; i++) {
		for(int j=1; j<=n; j++) {
			dp[i][j] = dp[i][j-1];
			count[i][j] = count[i][j];
		}
	}
	return 0;
}
