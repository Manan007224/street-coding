#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lst;
typedef unordered_map<int> map;

int max_array(lst &n){
	map a,b;
	int sum=0;
	int mx=0;
	for(int k=0;k<n.size();k++) 
		a[n[k]]=k;
	for(auto k: n){
		sum+=k;
		auto it=b.find(sum+3);
		if(it!=b.end()){
			i=b[sum+3]
			mx=max(mx,b[sum+3]-a[i]);
		}
		else b[sum]=n;
	}
}
