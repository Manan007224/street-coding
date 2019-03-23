#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
    	if(nums.size() ==0 || nums.size() == 1) return 0;
      int ans = merge_sort(nums, 0, nums.size());
      return ans;
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
  vi t = {2,4,3,5,1};
  Solution sln;
  cout << sln.reversePairs(t) << endl;
  inplace_merge(t.begin(), t.begin()+2, t.end());
  for(auto x: t) cout << x << " " ;
  cout << endl;
  return 0;
}