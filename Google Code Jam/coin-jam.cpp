#include <iostream>
#include <algorithm>
#include <vector>
#include "math.h"
using namespace std;

int main() {
	int t; cin>>t;
	while(t-- > 0) {
		int k; int c; int s; cin>>k>>c>>s;
		if(k > c*s) {
			cout << "IMPOSSIBLE" << endl;
			break;
		}
		for(int i=0;i<k;i+=c) {
			long long cnt = 0;
			for(int j=0;j<c;j++) cnt = cnt*k + min(i+j, k-1); 
			cout << cnt+1 << endl;
		}
	}
	cout << endl;
	return 0;
}
