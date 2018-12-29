

#include <bits/stdc++.h>
using namespace std;

int sign(int a) {
	if (a > 0) return 1;
	else return -1;
}

int abs(int a) {
	if (a<0) return -1*a;
	else return a;
}

vector<int> sum(vector<int> a, vector<int> b) {
	unordered_map<int, int> m;
	vector<int> v;
	
	for (int& i : a) {
		m[abs(i)] = sign(i);
	}
	
	for (int& i: b) {
		if (m.find(abs(i)) != m.end()) {
			int r = m[abs(i)] + sign(i);
			if (r!=0) {
				v.push_back(sign(r) * abs(i));
			}
		}
	}
	for(auto& x: m){
		cout<<x.first<<", "<<x.second<<endl;
	}
	cout<<v.size()<<" is hehe\n";
	return v;
}

int main(){
	int n,k; cin>>n>>k;
	int a; cin>>a; vector<int> va(a); for(int& x: va) cin>>x;
	int b; cin>>b; vector<int> vb(a); for(int& x: vb) cin>>x;
	
	vector<int>  v=sum(va,vb);
	cout << "b:" << v.size() << endl;
	for (int i : v){
		cout << i << endl;
	}
	
}

