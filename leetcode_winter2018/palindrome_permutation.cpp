#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
    	if(s.length()==0) return 0;
        unordered_set<char> r;
        for(auto t: s) {
        	auto ff = r.find(t);
        	ff == r.end() ? r.insert(t) : r.erase(ff);
        }
        return r.size()<=1;
    }
};

int main() {
	string s = "acb";
	string s1 = "carerac";
	Solution sln;
	cout<<sln.canPermutePalindrome(s1)<<endl;
	return 0;
}