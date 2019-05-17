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
	
vector<pii> dir = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

class Solution {
public:
  bool isRobotBounded(string instructions) {
  	int c = 0, x = 0, y = 0;
  	for(auto it: instructions) {
  		if(it == 'G') x += dir[c].fi, y += dir[c].se;
  		else if(it == 'L') c = (c+3)%4;
  		else c = (c+1)%4;
  	}
  	if((x==0 && y==0) || c > 0) return 1;
  	else return 0;
  }
};

int main() {
	Solution sln;
	cout << sln.isRobotBounded("GLG") << endl;
	return 0;
}