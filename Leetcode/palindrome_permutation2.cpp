#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef unordered_map<char,int> ump;
typedef unordered_set<char> ust;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
       	ump M;	
        ust ch;
        string mid = "";
        vs res;
        if(s.length() == 0) return res;
        for(auto t:s){
        	auto ff = ch.find(t);
        	auto fm = M.find(t);
        	if(fm == M.end()) M[t] = 0;
        	M[t]++;
        	if(ff == ch.end()) ch.insert(t);
        	else ch.erase(ff);
        }
        if(ch.size() > 1) return res;
        if(ch.size() == 1) mid = *(ch.begin()), M[*ch.begin()]--;
        go(M, "", s.length(), 0, mid, res);
        return res;
    }

    void go(ump &rec, string cr, int L, int c, string mid, vs &res) {
    	if(c*2 + mid.length() == L){
    		string tp = cr;
    		reverse(tp.rbegin(),tp.rend());
    		res.push_back(cr + mid + tp);
    	}
    	for(auto& r:rec){
    		if(r.second != 0) {
    			r.second -= 2;
    			go(rec, cr+r.first, L, c+1, mid, res);
    			r.second += 2;
    		}
    	}
    }
};

int main() {
	string r = "carerac";
	string r1 = "bacba";
	string r2 = "aaa";
	string r3 = "aabcbaa";
	Solution sln;
	vs res = sln.generatePalindromes(r);
	for(auto r: res) cout<<r<<endl;
	return 0;
}