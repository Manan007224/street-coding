#include <iostream>
#include <map>
#include <vector>
using namespace std ;
using ll = long long ;
const ll MOD { 998244353 } ;
ll choose(ll a, ll b) {
   if (b < 0 || b > a)
      return 0 ;
   if (b + b > a)
      b = a - b ;
   int r { 1 } ;
   for (int i=1; i<=b; i++)
      r = r * (a - i + 1) / i ;
   return r ;
}
int main() {
   int N{}, K{} ;
   cin >> N >> K ;
   map<int, int> cnts ;
   for (int i=0; i<N; i++) {
      int t{} ;
      cin >> t ;
      cnts[t]++ ;
   }
   vector<ll> res ;
   res.push_back(1) ;
   for (auto p : cnts) {
      vector<ll> res2(res.begin(), res.end()) ;
      res2.push_back(0) ;
      for (int i=0; i<(int)res.size(); i++)
         res2[i+1] = (res2[i+1] + p.second * res[i]) % MOD ;
      swap(res, res2) ;
   }
   cout << (K < (int)res.size() ? res[K] : 0) << endl ;
}
