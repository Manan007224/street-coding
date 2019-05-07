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
  int maxDistToClosest(vector<int>& seats) {
  	int n = seats.size();
  	int last = -1, res = 0;
  	for(int i=0; i<n; i++) {
  		if(seats[i]) {		
  			res = max((last < 0 ? i : (i-last)/2), res);
  			last = i; 
  		}
  	}
  	res = max(res, n-1-last);
  	return res;
  }
};

int main() {
	vector<int> arr = {1,0,0,0,1,0,1};
	vector<int> arr1 = {1,0,0,0};
	vector<int> arr2 = {0,0,1};
	vector<int> arr3 = {1,0,0,1};
	Solution sln;
	cout << sln.maxDistToClosest(arr) << endl;
	cout << sln.maxDistToClosest(arr1) << endl;
	cout << sln.maxDistToClosest(arr2) << endl;
	cout << sln.maxDistToClosest(arr3) << endl;
	return 0;
}