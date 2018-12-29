#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int ll=nums.size();
        vector<int> bf(ll), af(ll), res(ll);
        bf[0]=1;
        af[ll-1]=1;
        for(int i=1;i<ll;i++) bf[i]=bf[i-1]*nums[i-1];
        for(int i=ll-2;i>=0;i--) af[i]=af[i+1]*nums[i+1];
        for(int i=0;i<ll;i++) res[i]=af[i]*bf[i];
        return res;
    }
};

int main(){
	vector<int> test={2,3,4,5};
	Solution sln;
	vector<int> ans=sln.productExceptSelf(test);
	for(auto a:ans) cout<<a<<endl;
	return 0;
}