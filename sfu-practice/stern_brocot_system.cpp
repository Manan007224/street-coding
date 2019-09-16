#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int u, d; cin >> u >> d;
		if(u == 1 && d == 1) break;
		int p1 = 0, p2 = 1, c1 = 1, c2 = 0;
		int x = 1,y = 1;
		string res = "";
		while(!(x == u && y == d)) {
			if(x * d > y * u) {
				res += "L";
				p2 = x, c2 = y;
			}
			else {
				res += "R";
				p1 = x, c1 = y;
			}
			x = p1 + p2, y = c1 + c2;
		}
		cout << res << endl;
	}
	return 0;
}