//https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
    	int ll=A[0].size();
    	int ans=0;
    	if(A.size()==0) return 0;
    	vector<bool> curr_check(ll,0);
    	for(int i=0;i<ll;i++){
    		vector<bool> prev_check(curr_check);
    		for(int j=0;j<A.size()-1;j++){
    			if(!curr_check[j]){
    				if(A[j][i]>A[j+1][i]){
    					ans++;
    					curr_check=prev_check;
    					break;
    				}
    				else if(A[j][i]<A[j+1][i]){
    					curr_check[j]=1;
    				}
    			}
    		}
    		bool done=1;
    		for(auto k:curr_check){
    			if(!k){
    				done=0;
    				break;
    			}
    		}
    		if(done) return ans; 
    	}
    	return ans;
    }
};

int main(){
	vector<string> vs = {"xga","xfb","yfb"};
	vector<string> vs1 = {"koccmoezl","hbccayhbd"};
	Solution sln;
	cout<<sln.minDeletionSize(vs1)<<endl;
	return 0;
}