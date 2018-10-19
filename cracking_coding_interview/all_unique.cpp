#include <bits/stdc++.h>
using namespace std;

bool all_unique(string str){
	vector<bool> check(256,false);
	for(int k=0;k<str.length();k++){
		int a = int(str[k]);
		if(check[a])
			return false;
		else check[a]=true;
	}
	return true;
}

int main(){
	string test = "mnekli";
	cout<<int('m')<<endl;
	cout<<all_unique(test)<<endl;
	return 0;
}
