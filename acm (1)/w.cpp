
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,s; cin>>n>>s;
	int mm=0;
	while(n--){
		int a; cin>>a;
		mm=max(mm,a);
	}
	mm*=s;
	if(mm%1000 > 0){
		mm+=1000;
	}
	cout<<(mm/1000)<<endl;
}


