#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

vector<int> parent;
vector<int> rnk;

void init(int nodes) {
	rnk.clear(), parent.clear();
	for(int n=0; n<nodes; n++) {
		parent.pb(n), rnk.pb(0);
	}
}

int find(int x) {
	if(parent[x] == x)
		return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void join(int x, int y) {
	int p1 = find(x);
	int p2 = find(y);
	if(p1==p2)
		return;
	if(rnk[p1]>=rnk[p2]) {
		if(rnk[p1]==rnk[p2]) rnk[p1]++;
		parent[p2] = p1;
	}
	else parent[p1] = p2;
}

int main() {
	int T; cin >> T;
	for(int t=0; t<T; t++) {
		int nodes; cin >> nodes;
		init(nodes);
		int suc = 0, unsuc = 0;
		while(1) {
			char ch; int x, y;
			cin >> ch >> x >> y;
			if(ch == ' ') break;
			if(ch=='c') join(x,y);
			else {
				if(find(x) == find(y)) suc ++;
				else unsuc ++;
			}
		}
		cout << suc << "," << unsuc << endl;
	}
	return 0;
}