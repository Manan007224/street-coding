#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	bool backspaceCompare(string S, string T){
		int i=0; int j=0; int i1=0; int j1=0;
		while(j<S.length()){
			if(S[j]=='#'){
				if(i>0) i--;
				j++;
			} 
			else S[i++]=S[j++];
		}
		while(j1<T.length()){
			if(T[j1]=='#'){
				if(i1>0) i1--;
				j1++;
			} 
			else T[i1++]=T[j1++];
		}
		return (S.erase(i,S.length()-i)==T.erase(i1,T.length()-i1));
	}
};

int main(){
	string tt1="a#c";
	string tt2="b";
	Solution sln;
	cout<<sln.backspaceCompare(tt1,tt2)<<endl;
	return 0;
}