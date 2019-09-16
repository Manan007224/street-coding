#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string strWithout3a3b(int A, int B) {
    string res = "";
    bool f = 0;
    while(A || B) {
    	int k = res.length();
    	if(k >= 2 && res.back() == res[k-2]) f = res[k-2] == 'b';
    	else f = A >= B;
    	if(f) res += 'a' , A--;
    	else res += 'b', B--;
    }
    return res;
  }
};

int main() {
	Solution sln;
	cout << sln.strWithout3a3b(4, 2) << endl;
	return 0;
} 