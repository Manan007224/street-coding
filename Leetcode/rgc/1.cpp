#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input) {
	vector<string> v;
	stringstream ts(input);
	string tk;
	while(getline(ts,tk,' ')) v.push_back(tk);
	return v;
}

vector<int> solution(string &A, string &B) {
	vector<string> la = split(A), lb = split(B);
	vector<int> fla, flb;
	unordered_map<char, int> rec;
	for(auto str : la) {
		rec.clear();
		char lo = str[0];
		rec[lo]++;
		for(int i = 1; i < str.length(); i++) {
			if(str[i] < lo) lo = str[i];
			rec[str[i]]++;
		}
		fla.push_back(rec[lo]);
	}
	for(auto str : lb) {
		rec.clear();
		char lo = str[0];
		rec[lo]++;
		for(int i = 1; i < str.length(); i++) {
			if(str[i] < lo) lo = str[i];
			rec[str[i]]++;
		}
		flb.push_back(rec[lo]);
	}
	sort(fla.begin(), fla.end());
	vector<int> res;	
	for(auto f : flb)
		res.push_back(lower_bound(fla.begin(), fla.end(), f) - fla.begin());
	return res;
}


int main() {
	string a = "bbb cc";
	string b = "a aa aaa aaaa";
	vector<int> res = solution(a, b);
	for(auto r : res) cout << r << endl;
	return 0;
}