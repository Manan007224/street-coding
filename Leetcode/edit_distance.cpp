#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second


class Solution {
public:
  int minDistance(string word1, string word2) {
  	int x = word1.length(), y = word2.length();
  	if(x==0 && y==0) return 0;
  	if(x==0) return y;
  	if(y==0) return x;
  	vii dp(x+1, vi(y+1, 0));
  	for(int i=1; i<=x; i++)
  		dp[i][0] = i;
  	for(int i=1; i<=y; i++)
  		dp[0][i] = i;
  	dp[0][0] = 0;
  	for(int i=1; i<=x; i++) {
  		for(int j=1; j<=y; j++) {
  			if(word1[i-1] == word2[j-1])
  				dp[i][j] = dp[i-1][j-1];
  			else {
  				dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
  			}
  		}
  	}
  	return dp[x][y];     
  }
};

int main() {
	string a = "horse", b = "ros";
	string a1 = "abcdef", b1 = "azced";
	Solution sln;
	cout << sln.minDistance(a,b) << endl;
	return 0;
}