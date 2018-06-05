#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; int right = height.size()-1;
        int area = 0;
        while(left<right) {
        	area = max(area, (min(height[left], height[right]))*(right-left));
        	if(height[left]<height[right])
        		left++;
        	else
        		right--;
        }
        return area;
    }
};

int main() {
	Solution sln;
	vector<int> v = {1,8,6,2,5,4,8,7};
	cout <<sln.maxArea(v);
}