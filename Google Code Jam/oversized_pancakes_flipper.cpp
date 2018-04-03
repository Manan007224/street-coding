#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin>>t;
	while(t>0) {
		t--;
		string s; cin>>s;
		int n; cin>>n;
		int imp=0; int num=0;
		for(int i=0;i<n-s.length();i++) {
			if(s[i]== '-') {
				num++;
				for(int j=i;j<i+n;j++) {//checking for the next three
				if(s[i] == '-') {s[j] = '+';}
				else {s[j] = '-';}
				}
			}
		}
		for(int i=0;i<n;i++) //checking if still any '-'
		{
			if(s[i] == '-') {imp++; break;}
		}
		if(imp++) {cout << "IMPOSSIBLE";}
		else {cout<<"Case #"<< t+1 << ": " << num++ << endl;}
	}
	return 0;
}