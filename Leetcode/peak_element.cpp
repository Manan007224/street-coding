#include <bits/stdc++.h>
using namespace std;

int find_peak(vector<int> &v, int start, int end){
	int mid = (start+end)/2;
	if((mid==0 || v[mid]>v[mid-1]) && (mid==v.size()-1 || v[mid]>v[mid+1]))
		return v[mid];
	else if(v[mid]<v[mid-1] && mid>0)
		return find_peak(v,start,mid-1);
	else
		return find_peak(v,mid+1,end);
}

int main() {
	vector<int> test = {1,3,20,4,1,0,7};
	cout << find_peak(test,0,6) << endl;
}