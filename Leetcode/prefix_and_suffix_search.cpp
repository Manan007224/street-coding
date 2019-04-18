#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

struct node{
	node* ch[26];
	vector<int> vis;
  node(){
  	for(int i=0;i<26;i++) ch[i]=NULL;
  }
};

class Trie {
private: 
	node* root;
public:
	Trie() {
		root = new node();
	}
	vector<int> rec;
	void add(string word, int idx) {
		node* curr = root;
		for(int i=0; i<word.length(); i++) {
			if(curr->ch[word[i]-'a']==NULL) {
				node* next = new node();
				curr->ch[word[i]-'a'] = next;
			}
			curr = curr->ch[word[i]-'a'];
			curr->vis.pb(idx);
		}
	}
	vector<int> search(string word) {
		node* curr = root;
		for(int i=0; i<word.length(); i++) {
			if(curr->ch[word[i]-'a']==NULL) {
				vector<int> scratch = {};
				return scratch;
			}
			else curr = curr->ch[word[i]-'a'];
		}
		return curr->vis;
	}
};

class WordFilter {
public:
	Trie Prefix;
	Trie Suffix;
  WordFilter(vector<string>& words) {
  	for(int i=0; i<words.size(); i++) {
  		Prefix.add(words[i], i);
  		reverse(words[i].begin(), words[i].end());
  		Suffix.add(words[i], i);
  	}
  }
  
  int f(string prefix, string suffix) {
  	reverse(suffix.begin(), suffix.end());
    vector<int> pfx = Prefix.search(prefix);
    vector<int> sfx = Suffix.search(suffix);
    int i = pfx.size()-1, j = sfx.size()-1;
    while(i>=0 && j>=0) {
    	if(pfx[i] == sfx[j])
    		return pfx[i];
    	pfx[i] > sfx[j] ? i-- : j--;
    }
    return -1;  
  }
};

int main() {
	vector<string> words = {"malan", "maj", "majan"};
	vector<string> words1 = {"apple"};
	WordFilter wf(words1);
	// cout << wf.f("ma", "aj") << endl;
	cout << wf.f("b", "") << endl;
	return 0;
}