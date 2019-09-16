#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int d, b; cin >> d >> b;
		int curr = 1;
		d--;
		while(d--) {
			curr = b % 2 == 0 ? curr * 2 + 1 : curr * 2;
			b -= b/2;
		}
		cout << curr << endl;
	}
	return 0;
}