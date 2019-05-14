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
  int leastBricks(vector<vector<int>>& wall) {
  	int n = wall.size();
  	int res = 0, sum = 0;
  	unordered_map<int,int> rec;
  	for(int i=0; i<n; i++) {
  		sum = 0;
  		for(int j=0; j<wall[i].size()-1; j++) {
  			sum += wall[i][j];
  			rec[sum] += 1;
  			res = max(res, rec[sum]);
  		}
  	}
  	return (n-res);   
  }
};

int main() {
	vii arr = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
	Solution sln;
	cout << sln.leastBricks(arr) << endl;
	return 0;
}