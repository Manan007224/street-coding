#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin, nums.end());
        vector<vector<int>> output;
        int s = nums.size()-1; 
        int e = 0;
        int m = (s+e)/2;
        while(s<e){
        	if(s+e+middle==0){
        		vector<int> p = {nums[s], nums[e], nums[middle]};
        		output.push_back(p);
        		e--;
        	}
        	else if(s+e+middle<0)
        		e++;
        	else
        		s++;	
        }
    }
};

int main(){

}