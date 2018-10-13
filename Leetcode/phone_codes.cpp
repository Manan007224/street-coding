#include <bits/stdc++.h>
using namespace std;

typedef vector<string> lst;

lst letters = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
"p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int code(string s1, lst &op){
	if(s1.length()==0){
		op.push_back(" ");
		return 1;
	}
	int f = stoi(s1.substr(0,1));
	int s;
	int a1 = code(s1.substr(1), op);
	int a2=0;
	for(int i=0;i<a1;i++){
		op[op.size()-1-i] = letters[f]+op[op.size()-i-1];
	}
	if(s1.length()>=2 && (stoi(s1.substr(0,2))<=26)){
		a2 = code(s1.substr(2), op);
		s = stoi(s1.substr(0,2));
	}
	for(int i=0;i<a2;i++){
		op[op.size()-i-1]=letters[s]+op[op.size()-i-1];
	}
	return a1+a2;
}


int main(){
	string test = "1123";
	lst output;
	int ans = code(test, output);
	for(auto it: output)
		cout<<it<<endl;
	return 0; 
}
