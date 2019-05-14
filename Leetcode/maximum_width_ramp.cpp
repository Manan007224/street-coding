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
  int maxWidthRamp(vector<int>& A) {
  	int n = A.size();
  	stack<int> st;
  	st.push(0);
  	int res = 0;
  	for(int i=1; i<n; i++) {
  		if(A[st.top()] > A[i]) st.push(i);
  	}
  	for(int i=n-1; i>=0; i--) {
  		while(!st.empty() && A[st.top()]<=A[i]) {
  			res = max(res, i-st.top());
  			st.pop();
  		}
  	}
  	return res;    
  }
};

int main() {
	vector<int> arr = {9,8,13,14,5,7,1,18};
	Solution sln;
	cout << sln.maxWidthRamp(arr) << endl;
	return 0;
}