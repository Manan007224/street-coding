#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

struct TrieNode{
	TrieNode* ch[26];
	bool end;
  TrieNode(){
    for(int i=0;i<26;i++) ch[i]=NULL;
    end = 0;
  }
};

class Solution {
public:
	TrieNode* root = new TrieNode();

	void insert(string word) {
		TrieNode *curr = root;
    for(auto w:word) {
      if(curr->ch[w]==NULL) {
        TrieNode* next = new TrieNode();
        curr->ch[w]=next;
      }
      curr=curr->ch[w];
    }
    curr->end=1;
	}

	void dfs(vcc &b, int r, int c, TrieNode *t, vector<string> &res, vector<vector<bool>> &v, string curr) {
		if(r<0 || r>=b.size() || c<0 || c>=b[0].size() || v[r][c]!=0) return;
		v[r][c]=1;
		if(t->end) {
			res.push_back(curr);
		}
		else {
			for(int i=0;i<4;i++) {
				char x = b[dx[i]+r][dy[i]+c];
				if(t->ch[x]!=NULL && v[dx[i]+r][dy[i]+c]!=0) {
					dfs(b,dx[i]+r,dy[i]+c,t->ch[x],res,v,curr+b[dx[i]+r][dy[i]+c]);
				}
			}
		}
		v[r][c]=0;
	}

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  	for(auto w: words) insert(w);
  	TrieNode *t = root;
  	int r = board.size(), c = board[0].size();
  	vector<vector<bool>> visited(r,vector<bool>(c,0));
  	vector<string> res;
  	for(int i=0; i<board.size(); i++) {
  		for(int j=0; j<board[0].size(); j++) {
  			if(t->ch[board[i][j]]!=NULL) {
  				string n = ""+board[i][j];
  				dfs(board,i,j,t->ch[board[i][j]],res,visited,n);
  			}
  		}
  	}     
 	}
};

int main() {
	return 0;
}