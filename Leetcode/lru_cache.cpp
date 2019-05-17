#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class LRUCache {
public:
  LRUCache(int capacity) {
    cap = capacity;  
  }
  
  int get(int key) {
    auto kv = cache.find(key);
    if(kv != cache.end()) {
      int value = cache[key]->se;
    	update_pref(key, value);
    	return value; 
    }
    return -1;
  }
  
  void put(int key, int value) {
  	auto kv = cache.find(key);
   	if(cache.find(key) == cache.end() && pref.size() == cap) {
   		auto evict = pref.back();
   		pref.pop_back();
   		cache.erase(evict.fi);
   	}
   	update_pref(key, value);   
  }

  void update_pref(int key, int value) {
  	auto kv = cache.find(key);
    if(kv != cache.end()) {
      pref.erase(kv->se);
    }
  	pref.emplace_front(key, value);
  	cache[key] = pref.begin();
  }

private:
	list<pii> pref;
	unordered_map<int, list<pii>::iterator> cache;
	int cap;
};


int main() {
	return 0;
}