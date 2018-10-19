#include <bits/stdc++.h>
using namespace std;

bool check_rotation(string &s1, string &s2){
	if(s1.length()!=s2.length())
		return false;
	char first = s1[0];
	int k=0;
	while(s2[++k]!=first);
	if(k==s2.length())
		return false;
	string temp = s2.substr(k);
	s2.erase(s2.begin()+k,s2.end());
	s2 = temp+s2;
	return (s1==s2);
}



int main(){
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	bool ans = check_rotation(str1,str2);
	cout<<ans<<endl;
	return 0;
}

