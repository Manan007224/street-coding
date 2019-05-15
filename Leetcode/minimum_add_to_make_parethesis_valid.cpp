#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string S) {
    int n = S.length();
    int left_c = 0, right_c = 0;
    for(int i=0; i<n; i++) {
    	if(S[i] == '(') left_c++;
    	else if(S[i] == ')') {
    		if(left_c <= 0) right_c++;
    		else left_c--;
    	}
    }
    return left_c+right_c;  
  }
};

int main() {
	Solution sln;
	cout << sln.minAddToMakeValid("()))((") << endl;
	return 0;
}