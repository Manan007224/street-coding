#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

void solve(vector<int> arr, int t) {
	for(int i=0; i<arr.size()-1; i++) {
		if(arr[i] > arr[i+1]){
			cout << "Case #" << t << ": " << i << endl;
			return;
		}
	}
	cout << "Case #" << t << ": OK" << endl;
}

int main() {
	int T; cin>>T;
	for(int t=1; t<=T; t++) {
		int n; cin >> n;
		vector<int> arr(n), odd, even;
		for(int i=0; i<n; i++) {
			int x; cin >> x;
			i%2 == 0 ? odd.pb(x) : even.pb(x);
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		for(int i=0; i<n; i++){
			i%2 == 0 ? arr[i]=odd[i/2] : arr[i]=even[i/2];
		}
		solve(arr, t);	
	}
	return 0;
}