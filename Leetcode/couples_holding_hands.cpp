#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:

	vector<int> arr;

	int find(int x) {
		if(arr[x] == x)
			return x;
		arr[x] = find(arr[x]);
		return arr[x];
	}

	void join(int x, int y) {
		arr[find(x)] = arr[find(y)];
	}

  int minSwapsCouples(vector<int>& row) {
  	int seats = row.size(), swaps = 0;
  	if(seats.size()==0)
  		return 0;
  	arr.clear();
  	for(int i=0; i<=(seats/2)-1; i++) arr.pb(i);
  	for(int i=0; i<seats; i+=2) {
  		int x = row[i]/2, y = row[i+1]/2;
  		if(find(x)!=find(y)) {
  			join(x,y);
  			swaps++;
  		}
  	}
  	return swaps;   
  }
};

int main() {
	vector<int> t = {0,7,5,3,4,6,2,1};
	vector<int> t1 = {3,2,0,1};
	vector<int> t2 = {0,2,1,3};
	Solution sln;
	cout << sln.minSwapsCouples(t) << endl;
	cout << sln.minSwapsCouples(t1) << endl;
	cout << sln.minSwapsCouples(t2) << endl;
	return 0;
}