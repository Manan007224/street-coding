#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
  		int ll=citations.size();
  		// if(ll==1 && citations[0]<1) return 0;
      	if(ll==0) return 0;
      	if(citations[ll-1]<1) return 0;
  		int lo{0}, hi{ll-1}, mid{};
  		while(lo<hi){
  			mid=lo+(hi-lo)/2;
  			if(citations[mid]>=ll-mid) hi=mid;
  			else lo=mid+1;
  		}
  		return ll-lo;
    }
};

int main(){
	vector<int> test={4,5,6,7,9,10};
	vector<int> test1={0,0,4,4};
	Solution sln;
	cout<<sln.hIndex(test1)<<endl;
	return 0;
}