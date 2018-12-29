#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int sz=A.size();
        vector<vector<int>> B(sz,vector<int>(sz,-1));
        for(int i=0;i<sz;i++){
        	for(int j=0;j<sz;j++){
        		B[i][j]=(A[i][sz-1-j]==0)?1:0;
        	}
        }
        return B;
    }
};

int main(){
	vector<vector<int>> test={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
	Solution sln;
	vector<vector<int>> ans=sln.flipAndInvertImage(test);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}