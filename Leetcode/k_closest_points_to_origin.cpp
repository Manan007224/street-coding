#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class Solution {
public:

	struct cmp {
		bool operator() (pii &a, pii &b) {
			int da = (pow(a.first,2) + pow(a.second,2));
			int db = (pow(b.first,2) + pow(b.second,2));
			return da >= db;
		}
	};

  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
  	priority_queue<pii, vector<pii>, cmp> pq;
  	vector<vector<int>> res;
  	for(auto p : points) pq.push({p[0],p[1]});
  	for(int i=0; i<K; i++) res.push_back({pq.top().first, pq.top().second}), pq.pop();
  	return res; 
  }
};

int main() {
	return 0;
}