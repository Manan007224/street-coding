#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minFlipsMonoIncr(string S) {
    int n = S.length(), prev_1 = 0;
    if(n==0 || n==1) return 0;
    int res = 0;
    for(int i=0; i<n; i++) {
    	if(S[i]=='1') prev_1++;
    	// check if it's better to convert all prev one's to zero or vice versa
    	if(S[i]=='0') res = min(res+1, prev_1);
    	else res = min(res, prev_1);
    }
    return res;
  }
};

int main() {
	Solution sln;
	cout << sln.minFlipsMonoIncr("010110") << endl;
	return 0;
}