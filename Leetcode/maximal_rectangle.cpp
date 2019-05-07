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
  int maximalRectangle(vector<vector<char>>& matrix) {
  	int r = matrix.size(); if(r==0) return 0;
  	int c = matrix[0].size(); if(c==0) return 0;
  	vector<int> dp(c, 0);
  	int max_area = 0;
  	for(int i=0; i<r; i++) {
  		for(int j=0; j<c; j++) {
  			if(matrix[i][j] == '0') dp[j] = 0;
  			else dp[j] += 1;
  		}
  		max_area = max(solve(dp), max_area);
  	}
  	return max_area;  
  }

  int solve(vector<int> &arr) {
		int n = arr.size();
		int area = 0, max_area = 0;
		stack<int> st;
		int i;
		for(i=0; i<n; ) {
			if(st.empty() || arr[st.top()] <= arr[i]) {
				st.push(i);
				i++;
			}
			else {
				int top = st.top();
				st.pop();
				area = (st.empty()) ? arr[top] * i : arr[top] * (i-st.top()-1);
				max_area = max(area, max_area);
			}
		}
		while(!st.empty()) {
			int top = st.top();
			st.pop();
			area = (st.empty()) ? arr[top] * i : arr[top] * (i-st.top()-1); 
			max_area = max(area, max_area);
		}
		return max_area;
	}
};


int main() {
	vector<vector<char>> a = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','0','1','0'}};
	Solution sln;
	vector<int> arr = {1, 0};
	cout << sln.solve(arr) << endl;
	cout << sln.maximalRectangle(a) << endl;
	return 0;
}