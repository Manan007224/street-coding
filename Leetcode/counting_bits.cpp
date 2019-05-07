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
  vector<int> countBits(int num) {
  	vector<int> bits(num+1, 0);
  	for(int i=1; i<=num; i++) {
  		int uc = i & (i-1);
  		bits[i] = bits[uc] + 1; 
  	}
  	return bits;    
  }
};

int main() {
	Solution sln;
	vector<int> res = sln.countBits(5);
	for(auto r: res) cout << r << endl;
	return 0;
}