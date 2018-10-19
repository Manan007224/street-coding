#include <bits/stdc++.h>
using namespace std;

typedef stack<int> st;

void stacksort(st &s1){
	st s2;
	while(!s1.empty()){
		int tp=s1.top();
		s1.pop();
		while(!s2.empty() && tp<s2.top()){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(tp);
	}
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

int main(){
	st ip;
	ip.push(4);
	ip.push(2);
	ip.push(3);
	ip.push(1);
	stacksort(ip);
	while(!ip.empty()){
		cout<<ip.top()<<endl;
		ip.pop();
	}
	return 0;
}