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
  int videoStitching(vector<vector<int>>& clips, int T) {
  	int n = clips.size();
  	sort(clips.begin(), clips.end());
  	vector<long long> dp(n, INT_MAX);
  	int i = 0;
  	for(; i<n; i++) {
  		if(clips[i][0]!=0) break;
  		dp[i] = 1;
  	}
  	for(; i<n; i++) {
  		for(int j=0; j<i; j++) {
  			if(clips[i][0] <= clips[j][1]) {
  				dp[i] = min(dp[i], dp[j]+1);
  			}
  		}
  	}
  	long long res = INT_MAX;
  	for(int i=0; i<n; i++) {
  		if(clips[i][1]>=T) res = min(res, dp[i]); 
  	}
    for(int i=0; i<n; i++) {
      cout << "(" << clips[i][0] << " " << clips[i][1] << ") => " << dp[i] << endl;
    }
  	return res == INT_MAX ? -1 : static_cast<int>(res);    
  }
};

int main() {
	vii arr = {{0,2}, {4,6}, {8,10}, {1,9}, {1,5}, {5,9}};
	vii arr1 = {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};
	Solution sln;
	cout << sln.videoStitching(arr1, 9) << endl;
	return 0;
}