#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include "math.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int,vi> pvi;
typedef long long ll;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
    	if(nums.size() ==0 || nums.size() == 1) return 0;
      auto ans = merge_sort(nums);
      return ans.first;	
    }

   	pvi merge_sort(vi arr) {
   		if(arr.size()<=1) return {0,arr};
   		int m = floor(arr.size()/2);
   		vi left(arr.begin(), arr.begin()+m), right(arr.begin()+m, arr.end());
   		auto x1 = merge_sort(left);
   		auto x2 = merge_sort(right);
   		vi lt = x1.second, rt = x2.second, res;
   		int i=0, j=0, ivn=x1.first+x2.first, lp=0, rp=0;
    	while(lp<lt.size() && rp<rt.size()) {
    		ll c1 = lt[lp], c2 = rt[rp];
    		if(c1 > 2*c2) ivn += (lt.size()-lp), rp++;
    		else lp++;
    	}
    	while(i<lt.size() && j<rt.size()) {
    		lt[i]<=rt[j] ? res.push_back(lt[i++]) : res.push_back(rt[j++]);
    	}
    	while(i<lt.size()) res.push_back(lt[i++]);
    	while(j<rt.size()) res.push_back(rt[j++]);
   		return {ivn, res}; 
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






