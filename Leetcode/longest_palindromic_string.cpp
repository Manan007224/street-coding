#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<bool>> llst;

class Solution {
public:
    string longestPalindrome(string s) {

    }

    int calculate(string &str, int s, int e, int mx){
    	if(s>e)
    		return 0;
    	if(s==e)
    		return 1;
    	if(str[s]==str[e]){
    		return 2+calculate(str,s+1,e-1,mx);
    	}
    	mx = max(calculate(str,s+1,e),calculate(str,s,e-1));
    	return mx;
    }
};

int main(){
	return 0;
}