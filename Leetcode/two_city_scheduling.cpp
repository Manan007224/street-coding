#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
  	int n = costs.size(), sum = 0;
  	sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){
  		return (a[0]-a[1] < b[0]-b[1]);
  	});
  	for(int i = 0; i < n/2; i++) sum += costs[i][0];
  	for(int i = n/2; i < n; i++) sum += costs[i][1];
  	return sum;
  }
};

int main() {
	vector<vector<int>> arr = {{10,20},{30,200},{400,50},{30,20}};
	Solution sln;
	int a = sln.twoCitySchedCost(arr);
	cout << a << endl;
	return 0;
}