#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

int find(vector<int> &arr, int x) {
	if(arr[x] == x)
		return x;
	arr[x] = find(arr, arr[x]);
	return arr[x];
}

void join(vector<int> &arr, int x, int y) {
	arr[find(arr, x)] = arr[find(arr, y)];
}

int main() {
	int T; cin >> T;
	for(int t=0; t<T; t++) {
		string large; cin >> large;
		vector<int> arr;
		for(int i=0;i<=large[0]-65; i++)
			arr.pb(i);
		while(1) {
			string x ; cin >> x;
			if(x.length()==0) break;
			join(arr, x[0]-65, x[1]-65);
		}
		set<int> subgraphs;
		for(int i=0; i<arr.size(); i++) 
			subgraphs.insert(arr[i]);
		cout << subgraphs.size() << endl; 
	}
	return 0;
}