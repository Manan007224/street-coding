#include <bits/stdc++.h>
using namespace std;

int closest_num(vector<int> &v, int key){
	if(key>=v[v.size()-1])
		return v[v.size()-1];
	if(key<=v[0])
		return v[0];
	int start = 0;
	int end = v.size();
	int mid;
	while(start<end){
		mid=(start+end)/2;
		if(key<v[mid]){
			if(mid>0 && v[mid-1]<key)
				return (key-v[mid]>=key-v[mid-1]) ? v[mid-1] : v[mid];
			else
				end = mid-1;
		}
		else{
			if(mid<v.size()-1 && v[mid+1]>key)
				return (key-v[mid]>=key-v[mid+1]) ? v[mid+1] : v[mid];
			else
				start = mid+1;
		}
	}
}

int main(){
	vector<int> temp = {2,5,6,7,8,8,9};
	int target = 4;
	cout << closest_num(temp, target) << endl;
	return 0;
}