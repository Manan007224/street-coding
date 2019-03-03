#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi H = {-1};


void push(int v) {
	H.push_back(v);
	for(int i=0; i<H.size(); i++) {
		if(H[i] > H[i/2]) swap(H[i], H[i/2]);
		else break;
	}
}

void pop() {
	int r = H.pop_back(), i = 1;
	while(i < H.size()-1) {
		int x = (i*2), y = (i*2)+1, s, b;
		if(H[x]>=H[i] && H[y]>=H[i]) break;
		else {
			H[x] >= H[y] ? s=x, b=y : b=x, s=y;
			if(H[i] > s) 
		}
	}
}


int main() {
	return 0;
}