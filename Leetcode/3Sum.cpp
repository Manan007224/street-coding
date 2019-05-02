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
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vii res;
    int t = 0;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++) {
      if(i>0 && nums[i]==nums[i-1]) continue;
      for(int j=i+1, k=n-1; j<k; ) {
        if(j-1>i && nums[j]==nums[j-1]) ++j;
        if(k+1<n && nums[k]==nums[k-1]) --k;
        else {
          int sum = nums[i]+nums[j]+nums[k];
          if(sum>t) --k;
          else if(sum<t) ++j;
          else {
            res.pb({nums[i], nums[j], nums[k]});
            ++j;
            --k;
          }
        } 
      }
    }
    return res; 
  }
};

int main(){
	vector<int> v = {-3,1,-5,-1,0,-1,3,-4,1,2,-1,-1,-4,-4};
	Solution sln;
	vii res = sln.threeSum(v);
  for(auto r: res) cout << r[0] << " " << r[1] << " " << r[2] << endl; 
	return 0;
}

