#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet(){

    }
    bool insert(int val){
        auto it = entries.find(val);
        if(it!=entries.end())
            return false;
        store.push_back(val);
        entries[val]=store.size()-1;
    } 

    bool remove(int val){
        auto it = entries.find(val);
        if(it==entries.end())
            return false;
        // Do the following work        
    } 
    int getRandom(){
        
    }
private:
    unordered_map<int,int> entries;
    vector<int> store;
    int used;
};

int main(){
    RandomizedSet st;
    bool flag = st.insert(3);
    bool flag1 = st.insert(4);
    bool flag2 = st.insert(5);
    bool flag3 = st.remove(5);
    int tp = st.getRandom();
    cout<<tp<<endl;
    return 0;
}