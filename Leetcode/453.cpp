//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums){
    	int ll=nums.size();
    	if(ll==0) return 0;
    	int moves{0}, idx{0}, mn{nums[0]};
    	for(int i=1;i<ll;i++){
    		if(nums[i]<mn){
    			mn=nums[i]; idx=i;
    		};
    	}
    	for(int i=0;i<ll;i++){
    		if(i!=idx) moves+=(nums[i]-mn);
    	}
    	return moves;
    }
};

int main(){
	vector<int> v = {1,2,3,7,5};
	Solution sln;
	cout<<sln.minMoves(v)<<endl;
	return 0;
}