#include <bits/stdc++.h>
using namespace std;

int fibn(int num){
	if(num==1) return 1;
	if(num==0) return 0;
	int first = 0;
	int second = 1;
	int third = 1;
	for(int i=2;i<=num;i++){
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

int main(){
	cout << fibn(2) << endl;
}