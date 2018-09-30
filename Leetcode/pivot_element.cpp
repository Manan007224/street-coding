#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &v, int key, int start, int end){
	if(start>end)
		return -1;
	int mid = (start+end)/2;
	if(v[mid]==key)
		return mid;
	else if(v[start]<=v[mid]){
		if(key>=v[start] && key<=v[mid])
			return find(v,key,start,mid-1);
		else
			return find(v,key,mid+1,end);
	}
	else
		if(key>=v[mid] && key<=v[end])
			return find(v,key,mid+1,end);
		else
			return find(v,key,start,mid-1);
}

int main() {
	vector<int> test = {18,19,27,3,7};
	cout << find(test,7,0,4) << endl;
	return 0;
}