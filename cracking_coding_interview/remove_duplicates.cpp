#include <bits/stdc++.h>
using namespace std;

void remove_duplicates(string &s){
	int checked = -1;
	int ll = s.length();
	for(int i=0; i<ll; i++){
		int j=0;
		while(j<=checked){
			if(s[i]==s[j]){
				s[i]='\0';
				break;
			}
			j++;
		}
		checked=i;
	}
}

int main(){
	string str = "aaabbcckl";
	remove_duplicates(str);
	cout<<str<<endl;
	return 0;
}