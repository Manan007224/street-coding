#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if(num==0) return true;
    	if(num==1) return true;
    	vector<int> p={2,3,5};
    	int x=0;
        while(num>1){
        	if(x>2) return false;
        	num%p[x]==0 ? num/=p[x] : x++;
        }
        return num==1;
    }
};

int main(){
	Solution sln;
	cout<<sln.isUgly(12)<<endl;
	cout<<sln.isUgly(14)<<endl;
	return 0;
}