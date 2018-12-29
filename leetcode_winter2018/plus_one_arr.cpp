#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int ll = digits.size()-1;
        for(int x=ll; x>=0; x--){
        	if(digits[x]==9) digits[x]=0;
        	else{
        		digits[x]++;
        		return digits;
        	}
        }
        digits[0]=1;
       	digits.push_back(0);
       	return digits;
    }
};

int main(){
	Solution sln;
	vector<int> test={9,9,9};
	vector<int> test1={7,9,9};
	vector<int> test2={1,2,3};
	sln.plusOne(test);
	sln.plusOne(test1);
	sln.plusOne(test2);
	for(auto x:test) cout<<x<<" ";
	cout<<endl;
	for(auto x:test1) cout<<x<<" ";
	cout<<endl;
	for(auto x:test2) cout<<x<<" ";
	cout<<endl;
	return 0;
}