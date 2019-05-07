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
  int hammingWeight(uint32_t n) {
  	int x = 0;
  	while(n) n &= (n-1), x++;
  	return x; 
  }
};

int main() {
	uint32_t n = 11001;
	Solution sln;
	cout << sln.hammingWeight(n) << endl;
	return 0;
}