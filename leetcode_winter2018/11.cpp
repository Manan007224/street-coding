//https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0;
        int hi=height.size()-1;
        int area=0;
        while(lo<hi){
        	int dx=(hi-lo);
        	int dy=min(height[lo],height[hi]);
        	area=max(area,abs(dx*dy));
        	(height[lo]>height[hi])?hi--:lo++;
        }
        return area;
    }

};


int main(){
	vector<int> test={1,8,6,2,5,4,8,3,7};
	Solution sln;
	cout<<sln.maxArea(test)<<endl;
	return 0;
}