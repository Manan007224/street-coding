#include <bits/stdc++.h>
using namespace std;
typedef vector<int,node*> vin;

struct node{
	node* ch[26];
	bool end;
  node(){
    for(int i=0;i<26;i++) ch[i]=NULL;
    end = 0;
    }
};

class Trie {
private:
  node* root;
public:
  Trie() {
    root = new node();
  }
  void insert(string word) {
    node *curr = root;
    for(auto w:word) {
      if(curr->ch[w]==NULL) {
        node* next = new node();
        curr->ch[w]=next;
      }
      curr=curr->ch[w];
    }
    curr->end=1;
  }
  void search(word) {
    if(word.length()==0) return 0;
    node* curr = root;
    for(auto w:word) {
      if(curr->ch[w]!=NULL) curr=curr->ch[w];
      else return 0;
    }
    return curr->end;
  }
  void prefix_search(word){
    if(word.length()==0) return 0;
    node* curr = root;
    for(auto w:word) {
      if(curr->ch[w]!=NULL) curr=curr->ch[w];
      else return 0;
    }
    return 1;
  }
  void regex_search(word){
    
  }
};

int main(){
    Trie dict;
    dict.insert("apple");
    cout<<dict.search("apple")<<endl;
    cout<<dict.search("app")<<endl;
    cout<<dict.startsWith("app")<<endl;
    dict.insert("app");
    cout<<dict.search("app")<<endl;
	return 0;
}