#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
	vector<int> arr = {1,6,5,11};
	int x = arr.size(), sum=0;
	vvb dp(x,vi(x+1,0));
	for(auto a:arr) sum+=a;
	for(int i=0; i<x; i++)
		dp[i][0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1;j<=sum; j++) {
			dp[i][j] = dp[i-1][j];
			if(j-arr[i-1]>=0)
				dp[i][j] |= dp[i-1][j-arr[i-1]];
		}
	}
	int diff = INT_MAX;
	for(int i=0; i<=sum; i++) {
		if(dp[n][i]) {
			diff = min(abs(i-(sum-i)));
		}
	}
}

/*
1, 6, 11, 5
*/