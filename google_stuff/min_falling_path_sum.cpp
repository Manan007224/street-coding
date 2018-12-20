#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef vector<lst> llst;
#define INF 0x3f3f3f3f

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	int sz = A.size();
        llst dp(sz, lst(sz, 0));
        for(int i=0; i<sz; i++)
        	dp[0][i]=A[0][i];
        for(int i=1;i<sz;i++){
        	for(int j=0;j<sz;j++){
        		int x1,x2,x3;
        		x1=(j>0)?dp[i-1][j-1]:INF;
        		x2=(j<sz-1)?dp[i-1][j+1]:INF;
        		x3=dp[i-1][j];
        		dp[i][j]=A[i][j]+min({x1,x2,x3});
        	}
        }
        cout<<"Printing the matrix"<<endl;
        return *(min_element(dp[sz-1].begin(),dp[sz-1].end()));
    }
};

int main(){
	llst test={{2,1,3},{6,5,4},{7,8,9}};
	Solution sln;
	cout<<sln.minFallingPathSum(test)<<endl;
	return 0;
}