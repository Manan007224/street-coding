#include <bits/stdc++.h>
using namespace std;

int * fun(){
	int a = 5;
	cout<<&a<<endl;
	return &a;
}

int main(){
	cout<<fun()<<endl;
}