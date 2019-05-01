#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<double> vi_32;
typedef vector<vi_32> vii_32;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  string pushDominoes(string dominoes) {
  	int n = dominoes.length();
  	string res = dominoes;
  	vector<int> L(n, 0), R(n, 0);
  	int l = -1, r = -1;
  	for(int i=0; i<n; i++) {
  		if(res[i]=='R') r = i;	
  		else if(res[i]=='.') R[i] = (r == -1 ? INT_MAX : i-r);
  		else r = -1;
  	}
  	for(int i=n-1; i>=0; i--) {
  		if(res[i]=='L') l = i;
  		else if(res[i]=='.') L[i] = (l == -1 ? INT_MAX : l-i);
  		else l = -1;
  	}
  	for(int i=0;i<n;i++) {
  		if(res[i]=='.'){
  			if(L[i] < R[i]) res[i] = 'L';
  			else if(R[i] < L[i]) res[i] = 'R';
  		}
  	}
  	return res;
  }
};

int main() {
	string s = ".L.R...LR..L..";
	Solution sln;
	cout << sln.pushDominoes(s) << endl;
	return 0;
}