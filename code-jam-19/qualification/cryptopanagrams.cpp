#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		i64 N, L;
		cin >> N >> L;
		vector<i64> prods(L), primes;
		for(int i=0; i<L; i++)
			cin >> prods[i];
		int p = 0;
		while(prods[p] != prods[p+1]) p++;
		i64 curr = __gcd(prods[p], prods[p+1]);
		primes.pb(prods[p]/curr), primes.pb(curr);
		i64 last = curr/prods[p+1];
		for(int i=p; i<L; i++) {
			last = __gcd(prods[i], prods[i+1]);
			primes.pb(last);
		}
		primes.pb(prods[L-1]/last);
		unordered_set<int> temp(primes.begin(), primes.end());
		vector<int> prime_vec(temp.begin(), temp.end());
		sort(prime_vec.begin(), prime_vec.end());
		unordered_map<i64, char> mp;
		for(i64 i=0; i<26; i++) 
			mp[prime_vec[i]] = 'A'+i;
		string ans = " ";
		for(i64 i=0; i<primes.size(); i++)
			ans += mp[primes[i]];
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}