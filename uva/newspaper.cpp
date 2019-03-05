#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	while(n--) {
		int t; cin>>t;
		double res = 0;
		string s;
		unordered_map<char,double> r;
		while(t--) {
			char k; cin >> k; double v; cin >> v;
			r[k]=v;
		}
		int a; cin>>a;
		cin.ignore();
		while(a--){
			s = ""; 
			getline(cin, s);
			for(auto t: s){
				if(r.find(t)!=r.end()) res += r[t];
			}
		}
		res /= 100;
		printf("%0.2f$\n", res);
	}
	return 0;
}