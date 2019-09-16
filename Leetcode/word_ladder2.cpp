#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
  	for(auto w: wordList) dict.insert(w);
		for(int i=0; i<beginWord.length(); i++) {
			string str = beginWord;
			for(int j=0; j<26; j++) {
				str[i] = 'a'+j;
				if(dict.find(str) != dict.end() && beginWord != str) graph[beginWord].insert(str);
			}
		}
		for(int i=0; i<endWord.length(); i++) {
			string str = endWord;
			for(int j=0; j<26; j++) {
				str[i] = 'a'+j;
				if(dict.find(str) != dict.end() && endWord != str) graph[endWord].insert(str);
			}
		}
		for(auto word: wordList) {
			for(int i=0; i<word.length(); i++) {
				string str = word;
				for(int j=0; j<26; j++) {
					str[i] = 'a'+j;
					if(dict.find(str) != dict.end() && word != str) graph[word].insert(str);
				}
			}
		}

		unordered_set<string> vis;
		vis.insert(beginWord);
		level[beginWord] = 0;
		queue<string> q;
		q.push(beginWord);
		while(!q.empty()) {
			string v = q.front();
			q.pop();
			for(auto u: graph[v]) {
				if(vis.find(u) == vis.end()) {
					level[u] = level[v] + 1;
					vis.insert(u);
					q.push(u);
				}
			}
		}

		vis.clear();

		vector<string> now = {beginWord};
		for(auto u : graph[beginWord]) {
			vis.insert(u);
			now.push_back(u);
			go(u, now, vis, endWord);
			now.pop_back();
		}

		// debug(graph);

		return R;
  }

  void go(string curr, vector<string> &now, unordered_set<string> &vis, string endWord) {		
  	if(curr == endWord) {
  		R.push_back(now);
  		return;
  	}
		for(auto u : graph[curr]) {
			if(vis.find(u) == vis.end() && level[curr] + 1 == level[u]) {
				now.push_back(u);
				vis.insert(u);
				go(u, now, vis, endWord);
				now.pop_back();
				vis.erase(vis.find(u));
			}
		}
  }

  void debug(unordered_map<string, unordered_set<string>> &graph) {
  	for(auto gp : graph) {
			cout << gp.first << " => "; for(auto g: gp.second) cout << g << " ";
			cout << endl;
		}
  }

private:
	vector<vector<string>> R;
	unordered_map<string, unordered_set<string>> graph;
	unordered_set<string> dict;
	unordered_map<string, int> level;
};

int main() {
	vector<string> d = {"hot","dot","dog","lot","log","cog"};
	Solution sln;
	vector<vector<string>> v = sln.findLadders("hit", "cog", d);
	for(auto vvv: v) {
		for(auto vv: vvv) cout << vv << " ";
		cout << endl;
	}
	return 0;
}