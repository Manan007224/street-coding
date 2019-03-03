#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vs r;	
        go("",0,r,n);
        return r;
    }

    void go(string n, int c, vs &r, int L) {
    	if(n.length()==2*L){
    		if(c==0) r.push_back(n);
    		return;
    	}
    	if(c+1<=L) go(n+"(", c+1, r, L);
    	if(c-1>=0) go(n+")", c-1, r, L);
    }
};

int main() {
	Solution sln;
	vs res = sln.generateParenthesis(1);
	for(auto r:res) cout << r << endl;
	return 0;
}