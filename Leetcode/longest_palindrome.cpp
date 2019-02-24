#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
    	int res {0};
        vector<int> mp(256);
        for(auto c:s) mp[int(c)]++;
        for(auto m:mp){
        	res += m / 2 * 2;
        	if(res%2==0 && m%2==1) res++;
        }
        return res;
    }
};

int main(){
	string str="manan";
	Solution sln;
	cout<<sln.longestPalindrome(str)<<endl;
	return 0;
}