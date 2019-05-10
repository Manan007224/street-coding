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
  int countNumbersWithUniqueDigits(int n) {
  	int res = 10, cnt = 9;
  	if(n==0) return 1;
  	if(n==1) return 10;
  	for(int i=2; i<=n; i++) {
  		cnt = cnt * (10 - i + 1);
  		res += cnt;
  	}
  	return res; 
  }
};

int main() {
	Solution sln;
	cout << sln.countNumbersWithUniqueDigits(3) << endl;
	return 0;
}