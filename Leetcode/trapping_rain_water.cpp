#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pt;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<pt> st;
        int hl=height.size();
        if(hl==0) return 0;
        int area=0;
        if(height[0]!=0) st.push({height[0],0});
        for(int i=1;i<hl;i++){
        	if(height[i]!=0){
        		int last{0}, dx{}, dy{};
    			while(!st.empty() && st.top().first<=height[i]){
    				auto cr=st.top();
    				dx=(i-cr.second-1), dy=cr.first-last;
    				area+=(dx*dy);
    				last=cr.first;
    				st.pop();
    			}
    			if(!st.empty()){
    				dx=(i-st.top().second-1), dy=height[i]-last;
    				if(dx*dy>=0) area+=dx*dy;
    			}
    		}
        	st.push({height[i],i});
        }
        return area;
    }
};

int main(){
	vector<int> check={3,2,0,1,0,4};
	vector<int> check1={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> check2={4,2,3};
	Solution sln;
	cout<<sln.trap(check)<<endl;
	cout<<sln.trap(check1)<<endl;
	cout<<sln.trap(check2)<<endl;
	return 0;
}