#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int l = nums.size();
        for(int k=0;k<l-2;k++){
        	int s = k+1;
        	int e = l-1;
        	while(s<e){
        		int a=nums[s];
        		int b=nums[k];
        		int c=nums[e];
        		if(a+b+c==0){
        			vector<int> tp = {a,b,c};
        			output.push_back(tp);
        			e--;
        			s++;
        			while(s<e && nums[s]==nums[e])
        				s++;
        			while(s<e && nums[e]==nums[e-1])
        				e--;
        		}
        		else if(a+b+c<0)
        			s++;
        		else
        			e--;
        	}
        }
        return output;
    }
};

int main(){
	vector<int> v = {-1, 0, 1, 2, -1, -4};
	Solution sln;
	sln.threeSum(v);
	return 0;
}

