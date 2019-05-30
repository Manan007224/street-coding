#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class Solution {
public:
	struct cmp {
		bool operator() (pii &a, pii &b) {
			return a.second < b.second;
		} 
	};
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
  	int n = barcodes.size();
  	unordered_map<int,int> mp;
  	priority_queue<pii, vector<pii>, cmp> pq;
  	for(auto b : barcodes) mp[b]++;
  	for(auto m : mp) pq.push({m.first,m.second});
  	int odd = 0, even = 1;
  	while(!pq.empty()) {
  		int k = pq.top().first, j = pq.top().second;
  		pq.pop();
  		while(odd<n && j>0) {
  			barcodes[odd] = k;
  			j--;
  			odd += 2;
  		}
  		while(even<n && j>0) {
  			barcodes[even] = k;
  			j--;
  			even += 2;
  		}
  	}
  	return barcodes;
  }
};

int main() {
	vector<int> arr = {2,2,1,3,2,1,3,1,1};
	Solution sln;
	vector<int> res = sln.rearrangeBarcodes(arr);
	for(auto r : res) cout << r << " ";
	cout << endl;
	return 0;
}