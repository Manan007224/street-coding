#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    int n = asteroids.size();
    if(n==0) return {};
    st.push(asteroids[n-1]);
    for(int i=n-2; i>=0; i--) {
      if(st.empty()) {
        st.push(asteroids[i]);
        continue;
      }
      int tp = st.top();
      if(asteroids[i] < 0) {
        st.push(asteroids[i]);
      }
      else {
        if(tp < 0 && abs(tp) <= asteroids[i]) {
        	while(!st.empty() && asteroids[i] > abs(st.top()) && st.top() < 0) st.pop();
        	if(!st.empty() && st.top() < 0) {
        		if(abs(st.top()) > asteroids[i]) continue;
        		if(abs(st.top()) == asteroids[i]) st.pop();
        		else st.push(asteroids[i]);
        	}
        	else st.push(asteroids[i]);
        }
        else if(st.top() > 0) st.push(asteroids[i]);
      }
    }
    vector<int> res;
    while(!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
  }
};

int main() {
	vector<int> test = {-2, 2, -1, -2};
	vector<int> test1 = {5, 10, -9, -15};
	Solution sln;
	vector<int> res = sln.asteroidCollision(test1);
	for(auto r: res) cout << r << " ";
	cout << endl;
	return 0;
}