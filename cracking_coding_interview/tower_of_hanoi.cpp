#include <bits/stdc++.h>
using namespace std;

typedef vector<int> lst;

void tower_of_hanoi(int n, lst &s1, lst &s2, lst &s3){
	if(n==1){
		int transfer = s1[s1.size()-1];
		s3.push_back(transfer);
		s1.pop_back();
		return;
	}
	tower_of_hanoi(n-1,s1,s3,s2);
	tower_of_hanoi(1,s1,s2,s3);
	tower_of_hanoi(n-1,s2,s1,s3);
}

int main(){
	vector<int> start = {5,4,3,2,1};
	vector<int> middle = {};
	vector<int> end = {};
	tower_of_hanoi(5,start,middle,end);
	for(auto e: end) cout<<e<<endl;
	return 0;
}