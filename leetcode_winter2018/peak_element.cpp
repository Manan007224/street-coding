#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ll=nums.size();
        if(ll==0) return -1;
        int lo{0}, mid{}, hi{ll-1};
        while(lo<hi){
        	mid=(lo+hi)/2;
        	nums[mid] < nums[mid+1] ? lo=mid+1 : hi=mid;
        }
        return lo;
    }
};

int main(){
	vector<int> v1={1,7,3,5,4,11,12,13,14};
	Solution sln;
	cout<<sln.findPeakElement(v1)<<endl;
	return 0;
}