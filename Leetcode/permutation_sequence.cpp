#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class Solution {
public:
    string getPermutation(int n, int k) {
    	if(n == 1) return "1";
        vi F(n+1);
        string res = "", T = "1";
       	F[0] = 1, F[1] = 1;
        for(int i=2; i<=n; i++){
        	T += to_string(i);
        	F[i] = i*F[i-1];
        }
        k--;
        for(int i=0; i<n-1; i++) {
        	int p = k/F[n-i-1];
        	res += T[p];
        	T.erase(p,1);
        	k -= (p*F[n-i-1]);
        }
        res += T[0];
        return res;	
    }
};

int main() {
	Solution sln;
	string res = sln.getPermutation(4,17);
	cout << res << endl;
	return 0;
}