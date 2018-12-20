#include <bits/stdc++.h>
using namespace std;

string solution(string &S, int K) {
    for(int x=0; x<S.length(); x++){
    	if(S[x]=='-') 
    		S.erase(S.begin()+x);
    }
    string ans="";
    int tp=0;
    for(int x=S.length()-1; x>=0; x--){
    	ans=S[x]+ans;
    	tp++;
    	if(tp%K==0 && tp!=S.length()){
    		ans="-"+ans;
    	}
    }
    return ans;
}

int main(){
	string tt="2-4A0r7-4k";
	cout<<solution(tt,4)<<endl;
	return 0;
}