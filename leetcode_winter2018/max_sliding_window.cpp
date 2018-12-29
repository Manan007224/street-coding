#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  		deque<int> dq;
  		vector<int> res;
  		int ll=nums.size();
  		if(ll==0) return res;
  		for(int i=0; i<ll; i++){
  			while(!dq.empty() && nums[i]>nums[dq.back()])
  				dq.pop_back();
  			dq.push_back(i);
  			// conditiion where max needs to be removed as it is outside of sliding window
  			if(i>=k && !dq.empty() && dq.front()==(i-k))
  				dq.pop_front();
  			if(i>=k-1) res.push_back(nums[dq.front()]);
  		}
  		return res;     
    }
};

int main(){
	vector<int> window={1,3,-1,-3,5,3,6,7};
	Solution sln;
	vector<int> ans=sln.maxSlidingWindow(window,3);
	for(auto a:ans) cout<<a<<endl;
	return 0;
}