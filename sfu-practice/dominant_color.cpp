#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> mp;

int init() {
	mp['1']=1, mp['2']=2, mp['3']=3, mp['4']=4, mp['5']=5;
	mp['6']=6, mp['7']=7, mp['8']=8, mp['9']=9;
	mp['A']=10, mp['B']=11, mp['C']=12, mp['D']=13, mp['E']=14, mp['F']=15;
}

string solve(string col) {
	int r = mp[col[1]]*16 + mp[col[2]];
	int g = mp[col[3]]*16 + mp[col[4]];
	int b = mp[col[5]]*16 + mp[col[6]];
	int mx = max({r,g,b});
	if((mx==r && mx==g) || (mx==r && mx==b) || (mx==b && mx==g) || (mx==b && mx==r && mx==g)) {
		int y=r+g, mg=r+b, c=g+b;
		int nmx = max({y,mg,c});
		if(nmx==y && nmx==mg && nmx==c) return "grey";
		else {
			if(nmx==y) return "yellow";
			else if(nmx==mg) return "magenta";
			else return "cyan";
		}
	}
	else {
		if(mx==r) return "red";
		else if(mx==g) return "green";
		else return "blue";
	}
}

int main() {
	int t; cin >> t;
	init();
	while(t > 0) {
		string col; cin >> col;
		string ans = solve(col);
		cout << ans << endl;
		t--;
	}
	return 0;
}