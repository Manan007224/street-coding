#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
   	int mid = binary_search(nums,0,nums.size()-1,target);
   	if(mid==-1) return {-1, -1};
   	int l1 = 0, r1 = mid-1, l2 = mid+1, r2 = nums.size()-1, lp=-1, rp=-1;
   	int next, prev = mid;
   	while(l1<=r1) {
   		next = binary_search(nums,l1,r1,target);
   		if(next==-1) {
   			lp = prev; 
   			break;
   		}
   		prev = next, r1=next-1; 
   	}
   	if(lp == -1) lp = prev;
   	prev = mid;
   	while(l2<=nums.size()-1) {
   		next = binary_search(nums,l2,r2,target);
   		if(next==-1) {
   			rp = prev; 
   			break;
   		}
   		prev = next, l2=next+1;
   	}
   	if(rp == -1) rp = prev;
   	return {lp, rp};
  }

  int binary_search(vi &nums, int lo, int hi, int target) {
  	while(lo<=hi) {
  		int mid = (lo+hi)/2;
    	if(nums[mid] == target) return mid;
    	nums[mid]>target ? hi=mid-1 : lo=mid+1;
  	}
  	return -1;
  }
};

int main() {
	vi T = {5,8,8,8,8,10};
	vi T1 = {1,1,1,1,1,1,1};
	Solution sln;
	vi res = sln.searchRange(T,6);
	for(auto r: res) cout << r << " ";
	cout << endl;
	return 0;
}