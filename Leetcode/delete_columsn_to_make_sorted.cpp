#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  int minDeletionSize(vector<string>& A) {
    int n = A.size(), ans = 0;
    int m = A[0].size();
    bool th = 0;
    vector<bool> curr(m, 0);
    for(int i=0; i<m; i++) {
    	vector<bool> prev = curr;
    	for(int j=0; j<n-1; j++) {
    		if(!curr[j]) {
    			if(A[j][i] > A[j+1][i]) {
    				curr = prev;
    				break;
    			}
    			else if(A[j][i] < A[j+1][i]) curr[j] = 1;
    		}
    	}
    	bool done = 0;
    	for(auto k: curr) {if(k) done=1;}
    	if(done) return ans;
    }
    return ans; 
  }
};

int main() {
	vector<string> arr = {"ca", "bb", "ac"};
	vector<string> arr1 = {"xc", "yb", "za"};
	Solution sln;
	cout << sln.minDeletionSize(arr1) << endl;
	return 0;
}