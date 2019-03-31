<<<<<<< HEAD
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include "math.h"
using namespace std;

typedef vector<int> vi;
typedef long long ll;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
      auto ans = merge_sort(nums);
      return ans.first;	
    }

   	int merge_sort(vi &N, int s, int e) {
   		if(e-s<=1) return 0;
      int m = (e-s)/2 + s;
      int a = merge_sort(N, s, m) + merge_sort(N, m, e);
      int i=s, j=m, ivn=0;
      while(i<m && j<e) {
        ll c1 = N[i], c2 = N[j];
        if(c1 > 2*c2){
          ivn += (m-i), j++;
        }
        else i++;
      }
      inplace_merge(N.begin()+s, N.begin()+m, N.begin()+e);
      return (a+ivn);
   	}
};

int main() {
	vector<int> t1 = {3,7,10,14,18,19,2,11,16,17,23,25};
	vector<int> t2 = {1,5,4,8,10,2,6,9,12,11,3,7};
	vi t = {1,3,2,3,1};
	vi sp = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
	vi tt = {50000,49999,49998,49997,49996,49995,49994,49993,49992}
	int x = sln.reversePairs(tt);
	cout << x << endl;
	return 0;
}
