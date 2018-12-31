#include <bits/stdc++.h>
using namespace std;

struct node{
	unordered_map<char,node*> child;
	bool is_end;
};

class WordDictionary {
private:
    node* root;
public:
	WordDictionary() {
      	root = new node();
      	root->is_end=false;  
    }
    
	void addWord(string word) {
       if(word.length()==0) return;
        node* curr=root;
        for(char& w:word){
            auto it=curr->child.find(w);
            if(it==curr->child.end()){
                node* next=new node();
                next->is_end=false;
                curr->child.insert({w,next});
            }
            curr=curr->child[w];
        }
        curr->is_end=true; 
    }

    bool search_recur(node* curr,string word) {
		bool ans=false;
		if(word.length()==1){
			if(word[0]=='.'){
				for(auto& ch: curr->child) ans=ans||(ch.second->is_end);
			}
			else{
				auto it=curr->child.find(word[0]);
				if(it==curr->child.end()) return false;
				node* src=curr->child[word[0]];
				ans=src->is_end;
			}
		}
		else{
			string tp=word.substr(1);
	        if(word[0]=='.'){
	        	for(auto& ch:curr->child){
	        		ans=ans||(search_recur(ch.second,tp));
	        	}
	        }
	        else{
	        	auto it=curr->child.find(word[0]);
	        	if(it==curr->child.end()) return false;
	        	node* src=curr->child[word[0]];
	        	ans=ans||search_recur(src,tp);
	        }
		}
		return ans;
    }

	bool search(string word) {
		node* curr=root;
        if(word.length()==0) return false;
        return search_recur(curr,word);
    }	
};

int main(){
	WordDictionary dict;
	dict.addWord("bad");
	dict.addWord("dad");
	dict.addWord("mad");
	cout<<dict.search("pad")<<endl;
	cout<<dict.search("bad")<<endl;
	cout<<dict.search(".ad")<<endl;
	cout<<dict.search("b..")<<endl;
	cout<<dict.search("c.d")<<endl;
	return 0;
}