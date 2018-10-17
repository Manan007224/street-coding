#include <bits/stdc++.h>
using namespace std;

void remove(string &s){
	int i=0; 
	int j=1;
	for(int k=0; k<s.length()-1; k++){
		if(s[k]==s[k+1])
			j++;
		else{
			s[++i]=s[j++];
		}
	}
	for(int k=i+1; k<s.length(); k++)
		s[k] = '\0';

}

int main(){
	string str = "aaabbbcckl";
	remove(str);
	cout<<str<<endl;
}