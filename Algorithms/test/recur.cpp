#include <bits/stdc++.h>
using namespace std;

int recur(int a){
	if(a==1) return a;
	else return recur(a/2)+a;
}

int main(){
	int ans = recur(8);
	cout<<ans<<endl;	
	return 0;
}
