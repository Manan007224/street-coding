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
	int count;
  node(){
    for(int i=0;i<26;i++) ch[i]=NULL;
    count = 0;
  }
};

class Trie {
private: 
	node* root;
public:
	Trie() {
		root = new node();
	}
	void add(string word) {
		node* curr = root;
		for(int i=word.length()-1; i>=0; i--) {
			if(curr->ch[word[i]-'A']==NULL) {
				node* next = new node();
				curr->ch[word[i]-'A'] = next;
			}
			curr = curr->ch[word[i]-'A'];
			curr->count++;
		}
	}
	int ans() {return calc(root);}
	int calc(node* now) {
		int child_count = 0;
		for(int i=0; i<26; i++) {
			if(now->ch[i]!=NULL){
				child_count += calc(now->ch[i]);
			}
		}
		// cout << now->count << " " << child_count << endl;
		if(now->count - child_count >= 2) child_count += 2;
		return child_count;
	}
};

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		int n; cin >> n;
		Trie dict;
		for(int i=0; i<n; i++) {
			string str; cin >> str;
			dict.add(str);
		}
		int res = dict.ans();
		cout << "Case #" << t << ": " <<  res << endl;
	}
	return 0;
}