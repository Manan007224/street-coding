#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;

struct cmp {
	bool operator() (pci &a, pci &b) {
		return a.second < b.second;
	}
};

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
  	unordered_map<char,int> mp;
  	for(auto t: tasks) mp[t]++;
  	priority_queue<int, vector<pci>, cmp> pq;
  	int k=0, t=0;
  	for(auto m: mp) pq.push({m.first,m.second});
  	while(k<tasks.size()) {
  		for(int i=0; i<=n; i++) {
  			t++;
  			if(!pq.empty()) {
  				pci now = pq.top();
  				pq.pop();
  				mp[now.first]--;
  				k++;
  				if(k==tasks.size()) return t;
  			}
  		}
  		for(auto m:mp){
  			if(m.second > 0) pq.push({m.first,m.second});	
  		}
  	}
  	return t;	
  }
};

int main() {
	Solution sln;
	vector<char> test = {'a','a','a','b','b','b'};
	cout << sln.leastInterval(test,2) << endl;
	return 0;
}