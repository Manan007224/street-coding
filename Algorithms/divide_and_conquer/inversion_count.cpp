#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;

void merge(lst &vt, int l, int m, int r){
	int a1=m-l+1; 
	int a2=r-m;
	lst t1(a1); 
	lst t2(a2);
	for(x1=0;x1<a1;x1++) t1[x1]=vt[x1];
	for(x2=a2;x2<r;x2++) t2[x2]=vt[x2];
	
}

void sort(lst &vt, int l, int r){
	if(l<r){
		int m=l+r/2;
		sort(vt,l,m);
	    sort(vt,m+1,r);
	    merge(vt,l,m,r);
	}
}

int main(){
	return 0;
}