#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
  	int n=arr.size();
  	if(n==0) return 0;
  	stack<int> st;
  	st.push(arr[0]);
  	for(int i=1; i<n; i++) {
  		if(arr[i]>=st.top()){
  			st.push(arr[i]);
  		}
  		else {
  			int mx = st.top();
				while(!st.empty() && arr[i]<st.top()) st.pop();
				st.push(mx);
  		}
  	}
  	return st.size();
  }
};

int main() {
	vector<int> arr = {2,1,3,4,4};
	vector<int> arr1 = {5,4,3,2,1};
	vector<int> arr2 = {4,2,2,1,1};
	Solution sln;
	cout << sln.maxChunksToSorted(arr2) << endl;
	cout << sln.maxChunksToSorted(arr) << endl;
	cout << sln.maxChunksToSorted(arr1) << endl;
	return 0;
}