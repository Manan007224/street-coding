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
vi dx = {-1,0,1};

class Solution {
public:
  bool canCross(vector<int>& stones) {
  	int n = stones.size();
  	unordered_map<int, unordered_set<int>> can_jump;
  	for(int i=0; i<n; i++) can_jump.insert({stones[i], unordered_set<int>()});
  	can_jump[1].insert(1);
  	for(int i=1; i<n-1; i++) {
  		for(auto j: can_jump[stones[i]]) {
  			for(auto x: dx) {
  				int k = x+j;
  				auto it = can_jump.find(stones[i]+k);
  				if(k > 0 && it!=can_jump.end()) {
  					can_jump[stones[i]+k].insert(k);
  				}
  			}
  		}
  	}
  	return can_jump[stones[n-1]].size() == 0 ? 0 : 1;    
  }
};

int main() {
	vector<int> arr = {0,1,3,5,6,8,12,17};
	vector<int> arr1 = {0,1,2,3,4,8,9,11};
	Solution sln;
	cout << sln.canCross(arr1) << endl;
	return 0;
}