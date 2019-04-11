#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	vi arr = {3,4,-1,0,6,2,3};
	vi dp(arr.size(),1);
	int ans = 1;
	for(int i=1; i<dp.size(); i++) {
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[i] <= dp[j])
				dp[i]++;
		}
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}