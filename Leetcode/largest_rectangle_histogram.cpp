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
  int largestRectangleArea(vector<int>& heights) {
   	int n = heights.size();
		int area = 0, max_area = 0;
		stack<int> st;
		int i = 0;
		while(i < n) {
			if(st.empty() || heights[st.top()] <= heights[i]) {
				st.push(i);
				i++;
			}
			else {
				int top = st.top();
				st.pop();
				area = (st.empty()) ? heights[top] * i : heights[top] * (i-st.top()-1);
				max_area = max(area, max_area);
			}
		}
		while(!st.empty()) {
			int top = st.top();
			st.pop();
			area = (st.empty()) ? heights[top] * i : heights[top] * (i-st.top()-1); 
			max_area = max(area, max_area);
		}
		return max_area; 
  }
};

int main() {
	vector<int> heights = {2,1,5,6,2,3};
	Solution sln;
	cout << sln.largestRectangleArea(heights) << endl;
	return 0;
}