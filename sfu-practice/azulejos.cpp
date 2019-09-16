#include <bits/stdc++.h>
using namespace std;

// price, pos, height
struct tpl {
	int x,y,z;
	tpl (): x(0), y(0), z(0) {}
	tpl (int a, int b, int c): x(a), y(b), z(c) {}
};

struct cmp {
	bool operator() (tpl &a, tpl &b) {
		return a.x < b.x;
	} 
};

int main() {
	int n; cin >> n;
	cmp c;
	vector<tpl> back(n), front(n);
	for(int i=0; i<n; i++) {
		int a; cin >> a; back[i] = tpl(a,i+1,0);
	}
	for(int i=0; i<n; i++) {
		int a; cin >> a; back[i].z = a;
	}
	for(int i=0; i<n; i++) {
		int a; cin >> a; front[i] = tpl(a,i+1,0);
	}
	for(int i=0; i<n; i++) {
		int a; cin >> a; front[i].z = a;
	}
	sort(back.begin(), back.end(), c);
	sort(front.begin(), front.end(), c);
	bool flag = 1;
	for(int i=0; i<n; i++) {
		if(back[i].z <= front[i].z) {
			flag = 0;
			break;
		}
	}
	if(!flag) cout << "impossible" << endl;
	else {
		for(auto b: back) cout << b.y << " ";
		cout << endl;
		for(auto f: front) cout << f.y << " ";
		cout << endl;
	}
	return 0;
}