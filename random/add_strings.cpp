#include <bits/stdc++.h>
using namespace std;

int main(){
	string a = "24997";
	string b = "988";
	string ans = "";
		
	int k1 = a.length()-1;
	int k2 = b.length()-1;
	int carry = 0;

	while(k1>=0 && k2>=0){
		int add = int(a[k1])+int(b[k2])+carry-48;
		if(add>57){
			add-=10;
			carry=1;
		}
		else carry = 0;
		ans = char(add) + ans;
		k1 --; 
		k2 --;
	}

	while(k1 >= 0){
		int add = int(a[k1])+carry;
		if (add>57){
			add -=10;
			carry=1;
		}
		else carry=0;
		ans = char(add)+ans;
		k1--;
	}
	
	while(k2 >=0){
		int add = int(b[k2])+carry;
		if (add>57){
			add -=10;
			carry=1;
		}
		else carry=0;
		ans = char(add)+ans;
		k2--;
	}



	if(carry==1) ans='1'+ans;
	cout<<ans<<endl;
	return 0;
}