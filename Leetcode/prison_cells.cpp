#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
  	vector<int> p = cells;
  	vector<vector<int>> c(14, vector<int>(8));
  	for(int i=0; i<min(14,N); i++) {
  		for(int j=1; j<7; j++) {
  			c[i][j] = ((p[j-1]==1 && p[j+1]==1) || (p[j-1]==0 && p[j+1]==0)) ? 1 : 0;
  		}
  		p = c[i];
  	}
  	return c[(N-1)%14];
  }
};

int main() {
	return 0;
}