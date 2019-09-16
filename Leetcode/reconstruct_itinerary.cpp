#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator() (string &a, string &b) {
		return (a>b);
	}
};

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
  	int n = tickets.size();
  	string start = "JFK";
  	for(auto t: tickets) {
  		cities[t[0]].push(t[1]);
  	}
  	vector<string> v;
  	dfs(start, v);
  	return {v.rbegin(), v.rend()};
  }

  void dfs(string curr, vector<string> &v) {
    auto &pq = cities[curr];
    while(!pq.empty()) {
      string next = pq.top();
      pq.pop();
      dfs(next, v);
    }
  	v.push_back(curr);
  }

private:
	unordered_map<string, priority_queue<string, vector<string>, compare>> cities;
};

int main() {
	vector<vector<string>> t = {{"jfk","sfo"},{"jfk","atl"},{"sfo","atl"},{"atl","jfk"},{"atl","sfo"}};
	Solution sln;
	vector<string> res = sln.findItinerary(t);
	for(auto r: res) cout << r << endl;
	return 0;
}