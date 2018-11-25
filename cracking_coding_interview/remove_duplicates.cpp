#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> lst_b;


// Using smart brute force
// O(n^2) run-time and O(1) space
void remove_duplicates(string &s){
	int checked=-1;
	int ll=s.length();
	int idx=0;
	for(int i=0;i<ll;i++){
		int j=0;
		while(j<=checked){
			if(s[i]==s[j]) break;
			j++;
		}
		//if not found in the checked elements
		if(j==i) s[idx++]=s[i];
		checked=i;
	}
	s=s.substr(0,idx);
}

// Using hashing 
// O(n) run-time and O(256) space
void remove_duplicates2(string &s){
	lst_b mask(256,true);
	int idx=0;
	for(auto x:s){
		if(mask[int(x)]){
			mask[int(x)]=false;
			s[idx++]=x;
		}
	}
	s=s.substr(0,idx);
}

// Using sets
// O(nlogn) time and O(n) space
void remove_duplicates3(string &s){
	set<char> mask;

}

// Using bitset
// O(n) time and O(1) space
// Most effecient
void remove_duplicates4(string &s){

}

int main(){
	string str="geeksforgeeks";
	remove_duplicates2(str);
	cout<<str<<endl;
	return 0;
}