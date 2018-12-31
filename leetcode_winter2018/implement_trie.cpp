#include <bits/stdc++.h>
using namespace std;

struct node{
	unordered_map<char,node*> children;
	bool is_end;
};

class Trie {
private:
    node* root;
public:
    Trie() {
        root = new node();
        root->is_end=false;
    }

    void insert(string word) {
        if(word.length()==0) return;
        node* curr=root;
        for(char& w:word){
            auto it=curr->children.find(w);
            if(it==curr->children.end()){
                node* next=new node();
                next->is_end=false;
                curr->children.insert({w,next});
            }
            curr=curr->children[w];
        }
        curr->is_end=true;
    }

    bool search(string word) {
       if(word.length()==0) return false; 
       node* curr=root;
       for(char& w:word){
            auto it=curr->children.find(w);
            if(it==curr->children.end()) return false;
            node* src=curr->children[w];
            curr=src;
       }
       return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        if(prefix.length()==0) return 0;
        node* curr=root;
        for(char& p: prefix){
            auto it=curr->children.find(p);
            if(it==curr->children.end()) return false;
            curr=curr->children[p];
        }
        return true;
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