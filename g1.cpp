#include <bits/stdc++.h>
#include <cctype>
using namespace std;

string solution(string &s, int K){
	int og = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]!='-')
			og++;
	}
	int parts = og/K; string r = "";
	int count = 0; int curr=0;
	for(int i=0;i<s.length();i++){
		if(count==parts){
			curr++;
			int next = (og-parts)/(K-curr);
			parts+=next;
			char add = '-';
			r+=add;
		}
		if(s[i]!='-'){
			count++;
			if(islower(s[i])) s[i] = toupper(s[i]);
			r+=s[i]; 
		}
	}
	return r;
}

int main() {
	string s = "2-4A0r7-4k";
	cout << solution(s,3) << endl;
	return 0;
}