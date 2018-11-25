#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;

int partition(lst &A,int l,int h){
	int pt=A[l];
	int x1=l;
	int x2=h;
	while(x1<x2){
		while(A[x1]<=pt) x1++;
		while(A[x2]>pt) x2--;
		if(x1<x2) swap(A[x1],A[x2]);
	}
	swap(A[l],A[x2]);
	return j;
}

void qsort(lst &A,int l,int h){
	if(l<h){
		int m=partition(A,l,h);
		qsort(A,l,m-1);
		qsort(A,m+1,h);
	}
}

int main(){
	lst vector<int> nums = {10,16,8,12,15,6,3,9,5};
	qsort(A,0,A.size()-1);
	for(auto x:nums) cout<<x<<" ";
	cout<<endl;
}
