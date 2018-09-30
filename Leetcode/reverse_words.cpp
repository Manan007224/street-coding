#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void reverseWords(string &s){
		int sz=s.length();
        for(int k=0;k<sz/2;k++){
			char tp=s[k];
			s[k]=s[sz-1-k];
			s[sz-1-k]=tp;
		}
		int cnt=0;
		for(int k=0;k<sz;k++){
			if(s[k]==' '){
				int run=k;
				for(int i=cnt;i<(run+cnt)/2;i++){
					char tp=s[i];
					s[i]=s[run+cnt-1-i];
					s[run+cnt-1-i]=tp;
				}
				cnt=k+1;
			}
		}
		for(int k=cnt;k<(sz+cnt)/2;k++){
			char tp=s[k];
			s[k]=s[(sz+cnt)-1-k];
			s[(sz+cnt)-1-k]=tp;
		}
    }
};

int main(){
	string s=" ";
	Solution sln;
	sln.reverseWords(s);
	cout<<s<<endl;
	return 0;
}
 