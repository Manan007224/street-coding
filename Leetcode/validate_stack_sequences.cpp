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
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  	int n = pushed.size();
  	int j = 0;
  	stack<int> st;
  	for(int i=0; i<n; i++) {
  		st.push(i);
  		while(!st.empty()) {
  			if(pushed[st.top()]==popped[j]) {
  				st.pop();
  				j++;
  			}
  			else break;
  		}
  	}
  	return st.empty();
  }
};

int main() {
	vector<int> pu = {1,2,3,4,5}, pp = {2,1,3,5,4}, pp1 = {4,5,3,1,2};
	Solution sln;
	cout << sln.validateStackSequences(pu, pp1) << endl;
	return 0;
}