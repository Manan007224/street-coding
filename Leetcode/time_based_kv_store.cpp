#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
  TimeMap() {}
  
  void set(string key, string value, int timestamp) {
  	store[key][timestamp] = value;
  }
  
  string get(string key, int timestamp) {
  	if(store.find(key) == store.end()) return "";
    auto mp = store[key];
    string res = fk(mp, timestamp);
    return res;
  }

  string fk(map<int, string> &mp, int k) {
  	auto begin = mp.begin();
  	auto end = mp.end(); end --;
  	if(begin->first > k) return "";
  	if(end->first < k) return end->second;
  	if(mp.find(k) != mp.end()) return mp[k];
  	auto lower = mp.lower_bound(k);
  	lower--;
  	return lower->second;
  }

private:
	unordered_map<string, map<int, string>> store;
};

int main() {
	TimeMap kv;
	kv.set("foo", "bar", 1);
	cout << kv.get("foo", 1) << endl;  // output "bar"   
	cout << kv.get("foo", 3) << endl;
	kv.set("foo", "bar2", 4);   
	cout << kv.get("foo", 4) << endl; // output "bar2"   
	cout << kv.get("foo", 5) << endl; //output "bar2"   
	return 0;
}