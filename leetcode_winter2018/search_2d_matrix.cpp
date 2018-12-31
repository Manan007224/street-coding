#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0) return false;
        int c=matrix[0].size();
        if(c==0) return false;
        int loc{0}, lor{0}, hic{c-1}, hir{r-1}, row{-1};
        while(lor <= hir){
        	int mid = (lor+hir)/2;
        	int start = matrix[mid][0];
        	int end = matrix[mid][c-1];
        	if(target>=start && target<=end){
        		row = mid;
        		break;
        	}
        	target > end ? lor=mid+1 : hir=mid-1;
        }
        if(row==-1) return false;
        while(loc <= hic){
        	int mid = (loc+hic)/2;
        	if(target==matrix[row][mid]) return true;
        	target > matrix[row][mid] ? loc=mid+1 : hic=mid-1;
        }
        return false;
    }
};

int main(){
	vector<vector<int>> v={{-9,-8,-8},{-5,-3,-2},{0,2,2},{4,6,8}};
	vector<vector<int>> v1={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	vector<vector<int>> v2={{1,3,5}};
	vector<vector<int>> v3={{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	Solution sln;
	cout<<sln.searchMatrix(v3,10)<<endl;
	return 0;
}