#include <bits/stdc++.h>
using namespace std;

int solution(string &S, string &T){
	if(S.length()<T.length())
		return 0;
	for(int i=0;i<S.length();i++){
		string ns = S.substr(0,i) + S.substr(i+1);
		// cout << "Just for testing " << ns << endl;
		if(ns == T)
			return 1;
		if(ns.length()<T.length())
			return 0; 
	}
	return 0;
}

int main(){
	string s = "a";
	string t = "a";
	cout << solution(s,t) << endl;
	return 0;
}