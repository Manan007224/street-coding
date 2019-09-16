#include <bits/stdc++.h>
using namespace std;

vector<string> split(string data) {
	int last = 0;
	vector<string> res;
	for(int i=0; i<data.length(); i++) {
		if(data[i] == "!" || data[i] == "'" || data[i] == "?" || data[i] == ";" || data[i] == "." || data[i] == " ") {
			string x = data.substr(last, i-last);
			last = i+1;
			if(x != "") {
				
				res.push_back(x);
			}
		}
	}
	return res;
}

class Solution {
public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    vector<int> p = split(paragraph);
    for(auto &x: banned) transform(x.begin(), x.end(), x.begin(), [](unsigned char c){ return tolower(c);});
    unordered_map<string,int> mp;
    for(auto i : p) mp[i]++;
    int x = 0;
    string y = "";
    for(auto m: mp) {
    	if()
    } 
  }
};

int main() {
	string x = "abcdefghijk";
	cout << x.substr(0, 2) << endl;
	return 0;
}