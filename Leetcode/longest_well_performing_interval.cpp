#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestWPI(vector<int>& hours) {
    int n = hours.size(), res = 0;
    unordered_map<int,int> rec;
    int curr = 0;
    for(int i=0; i<n; i++) {
    	hours[i] > 8 ? curr++ : curr--;
    	if(curr > 0) res = i + 1;
    	else {
    		if(rec.find(curr) == rec.end()) rec[curr] = i;
    		if(rec.find(curr-1) != rec.end()) {
    			res = max(i-rec[curr-1], res);
    		}
    	}
    }
    return res; 
  }
};