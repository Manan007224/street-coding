#include <bits/stdc++.h>
using namespace std;
ptypedef vector<int> vi;
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
  int nthSuperUglyNumber(int n, vector<int>& primes) {
  	priority_queue<i64, vector<i64>, greater<i64>> pq;
  	unordered_set<i64> st;
  	if(n==1 || n==0) return 1;
  	pq.push(1);
  	st.insert(1);
  	i64 cnt;
  	for(int i=0; i<n; i++) {
  		cnt = pq.top();
  		pq.pop();
  		for(auto p: primes) {
  			if(st.find(cnt*p)==st.end()) pq.push(cnt*p), st.insert(cnt*p);
  		}
  	}
  	return static_cast<int>(cnt);	  
  }
};

int main() {
	vector<int> p = {2,7,13,19};
	Solution sln;
	cout << sln.nthSuperUglyNumber(12, p) << endl;
	return 0;
}