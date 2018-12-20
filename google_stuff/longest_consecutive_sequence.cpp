#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	unordered_set<int> s;
        int ll = nums.size();
        if(ll==0) return 0;
        for(auto x: nums) s.insert(x);
        int lr=1;
        for(int x=0; x<ll; x++){
            if(s.find(nums[x]-1)==s.end()){
                int k=nums[x];
                while(s.find(k)!=s.end()) k++;
                lr=max(lr,k-nums[x]);
            }
        }
        return lr;
    }   
};

int main(){
	vector<int> test={100,4,200,1,3,2,500,0,-1,4};
	Solution sln;
	int a=sln.longestConsecutive(test);
    cout<<a<<endl;
	return 0;
}