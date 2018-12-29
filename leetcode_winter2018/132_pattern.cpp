#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int ll=nums.size();
    	if(ll<=2) return 0;
    	vector<int> a(ll);
    	a[0]=nums[0];
    	stack<int> st;
    	for(int i=1;i<ll;i++) a[i]=min(a[i-1],nums[i]);
    	for(int i=ll-1;i>=0;i--){
    		if(nums[i]>a[i]){
    			while(!st.empty() && st.top()<=a[i])
    				st.pop();
    			if(!st.empty() && st.top()<nums[i])
    				return true;
    			st.push(nums[i]);
    		}
    	}
    	return true; 
    }
};

int main(){
	vector<int> t1={3,1,4,2};
	vector<int> t2={1,2,3,4};
	Solution sln;
	cout<<sln.find132pattern(t2)<<endl;
	return 0;
}