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
bool compare(vector<int> &a, vector<int> &b) {return (a[1] < b[1]);}

class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    if(n==0) return 0;
    int res = 0;
    vector<int> dp(n, 1);
    for(int i=1; i<n; i++) {
    	for(int j=0; j<i; j++) {
    		if(pairs[i][0] > pairs[j][1]) {
    			dp[i] = max(dp[i], dp[j]+1);
    			res = max(res, dp[i]);
    		}
    	} 
    }
    return res;
  }
};

int main() {
	vii arr = {{1,2}, {2,3}, {3,4}};
	Solution sln;
	cout << sln.findLongestChain(arr) << endl;
	return 0;
}