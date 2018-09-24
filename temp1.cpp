#include <bits/stdc++.h>
using namespace std;


int k(int tm, int td, vector<int> &c, vector<int> &d, int n){
	if(tm==0 || td==0)
		return 0;
	int total;
	if(c[n-1]>tm)
		total = k(tm,td,c,d,n-1);
	else
		total = max(d[n-1] + k(tm-c[n-1],td,c,d,n-1));
	if(total>=td && total<=tm)
		return 1;
}

bool solution(int total_money, int total_damage, vector<int> &costs, vector<int> &damages) {
	if(k(total_money, total_damage, costs, damages, costs.size()) == 1)
		return true;
	else 
		return false; 
}



int main(){

	return 0;
}