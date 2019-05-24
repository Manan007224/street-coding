#include <bits/stdc++.h>
using namespace std;

const double L = 1e-6;

class Solution {
public:
  double minmaxGasDist(vector<int>& stations, int K) {
  	int n = stations.size();
  	double hi = stations[n-1] - stations[0];
  	double lo = 0;
  	while(lo < hi - L) {
  		double mid = (lo + hi)/2;
  		int sum = 0;
  		for(int i=0; i<stations.size()-1; i++) {
  			sum += int((stations[i+1]-stations[i])/mid);
  		}
  		if(sum <= K) hi = mid;
  		else lo = mid;
  	}
  	return hi;
  }
};


int main() {
	vector<int> t = {1,2,3,4,5,6,7,8,9,16};
	Solution sln;
	cout << sln.minmaxGasDist(t, 5) << endl;
	return 0;
}