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
  int integerBreak(int n) {
  	int res = 1;
  	if(n==1 || n==2) return 1;
    if(n==3) return 2;
  	int cnt = n % 3 == 1 ? (n/3)-1 : n/3;
  	for(int i=0; i<cnt; i++) res *= 3;
  	int left = n - (cnt*3);
  	for(int i=0; i<left/2; i++) res *= 2;
  	return res;
  }
};

int main() {
	Solution sln;
	cout << sln.integerBreak(3) << endl;
	return 0;
}