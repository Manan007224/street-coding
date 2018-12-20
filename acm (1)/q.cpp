
#include <bits/stdc++.h>
using namespace std;

int main(){
	map<char, int> m;
	for(int i=0;i<5;i++){
		string s; cin>>s;
		m[s[0]]++;
	}
	int mm=0;
	for(auto& x: m){
		mm=max(x.second, mm);
	}
	cout<<mm<<endl;
}

