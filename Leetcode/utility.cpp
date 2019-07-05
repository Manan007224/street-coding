#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
	vii a(4, vi(4)), b(4, vi(4)), c(4, vi(4));
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) cin >> a[i][j];
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) cin >> b[i][j];
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			for(int k=0; k<4; k++) {
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) cout << c[i][j] << " ";
		cout << endl;
	}
}