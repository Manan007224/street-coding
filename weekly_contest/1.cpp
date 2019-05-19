#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

struct cmp {
  bool operator() (int &a, int &b) {
    return a < b;
  }
};

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();
    priority_queue<int, vector<int>, cmp> pq;
    for(auto s: stones) pq.push(s);
    while(pq.size() > 1) {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      // cout << a << " " << b << endl;
      int diff = abs(a-b);
      if(diff!=0) pq.push(diff);
    }
    if(!pq.size()) return 0;
    else return pq.top();
  }
};

int main() {
	vector<int> arr = {2,7,4,1,8,1};
	vector<int> arr1 = {2};
	vector<int> arr2 = {2,7,4,1,8};
	Solution sln;
	cout << sln.lastStoneWeight(arr) << endl;
	cout << sln.lastStoneWeight(arr1) << endl;
	cout << sln.lastStoneWeight(arr2) << endl;
	return 0;
}