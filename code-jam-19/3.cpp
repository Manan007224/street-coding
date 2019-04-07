#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pt;
typedef priority_queue<int,vi,greater<int>> PQ;

const int MAX = 1000001; 
int F[MAX] = { 0 };

void sieve() {
	F[0] = 1; 
  F[1] = 1; 
  for (int i = 2; i < MAX; i++) F[i] = i; 
  for (int i = 4; i < MAX; i += 2) F[i] = 2;  
  for (int i = 3; i * i < MAX; i++) { 
    if (F[i] == i) { 
      for (int j = i * i; j < MAX; j += i) { 
        if (F[j] == j) F[j] = i; 
      } 
    } 
  } 
} 

vi p_fac(int n) {
	vi res;
  for(int i=2; i<MAX; i++) {
  	if(n<=1) break;
  	if(n%F[i]==0) res.push_back(i), n /= F[i];
  }
  return res;
} 

int main() {
	int t; cin>>t;
	sieve();
	for(int a=1;a<=t;a++) {
		PQ pq;
		unordered_map<int,pt> facs;
		unordered_map<int,char> mp;
		unordered_set<int> s;
		int N,L; cin>>N>>L;
		vi prods(L);
		for(int i=0;i<L;i++) cin>>prods[i];
		int cnt = 0;
		for(auto p:prods) {
			auto x = p_fac(p);
			facs[p] = {x[0],x[1]};
			if(s.find(x[0])==s.end()) pq.push(x[0]), s.insert(x[0]);
			if(s.find(x[1])==s.end()) pq.push(x[1]), s.insert(x[1]);
		}
		int i=0;
		while(!pq.empty()) {
			mp.insert({pq.top(),'A'+i});
			pq.pop();
			i++;
		}
		string ans="";
		char xx=mp[facs[prods[0]].first],yy=mp[facs[prods[0]].second];
		ans+=xx;
		ans+=yy;
		cout << facs[prods[0]].first<<" " << facs[prods[0]].second<< " "<<prods[0]<<endl;
		for(int i=1; i<prods.size(); i++) {
			cout << facs[prods[i]].first<<" " << facs[prods[i]].second<< " "<<prods[i]<<endl;
			xx = mp[facs[prods[i]].first];
			yy = mp[facs[prods[i]].second];
			if(mp[facs[prods[i-1]].first]==xx||mp[facs[prods[i-1]].second]==xx) ans+=yy;
			else ans+=xx;
		}
		cout<<"Case #"<<a<<": "<<ans<<endl;
	}
	return 0;
}