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
  int oddEvenJumps(vector<int>& A) {
  	int n = A.size();
  	vector<bool> odd(n, 0), even(n, 0);
  	odd[n-1] = 1, even[n-1] = 1;
  	map<int,int> tree;
    tree[A[n-1]] = n-1;
    int res = 1;
  	for(int i=n-2; i>=0; i--) {
  		auto hi = tree.upper_bound(A[i]);
  		auto lo = tree.lower_bound(A[i]);
  		if(hi != tree.end())
  			odd[i] = even[hi->se];
  		if(lo != tree.begin())
  			even[i] = odd[(--lo)->se];
  		if(odd[i]) res++;
      tree[A[i]] = i;
  	}
  	return res;      
  }
};

int main() {
	vector<int> t = {2,3,1,1,4};
  vector<int> t1 = {5,1,3,4,2};
  vector<int> t2 = {10,13,12,14,15};
	Solution sln;
	cout << sln.oddEvenJumps(t) << endl;
	return 0;
}