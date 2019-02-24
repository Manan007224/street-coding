#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi=numbers.size()-1;
        vector<int> res(2);
        while(lo<hi){
        	if(numbers[lo]+numbers[hi]==target)
        		res[0]=lo+1, res[1]=hi+1;
        	numbers[lo]+numbers[hi] > target ? hi-- : lo++;
        }
        return res;
    }
};

int main(){
	vector<int> test={2,7,11,15};
	Solution sln;
	vector<int> ans=sln.twoSum(test,9);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}