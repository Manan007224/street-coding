#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
using ll = long long ;
using pii = pair<ll, ll> ;
using riv = vector<pii> ;
ll sgn(ll v) {
   if (v < 0)
      return -1 ;
   if (v > 0)
      return 1 ;
   return 0 ;
}
riv readriv() {
   riv r ;
   ll m{}, v{} ;
   cin >> m ;
   for (ll i=0; i<m; i++) {
      cin >> v ;
      r.push_back(make_pair(abs(v), sgn(v))) ;
   }
   return r ;
}
riv compose(const riv &a, const riv &b, ll(*f)(ll, ll)) {
   riv r ;
   auto ap = a.begin() ;
   auto bp = b.begin() ;
   while (ap != a.end() || bp != b.end()) {
      ll v{}, loc{} ;
      if (ap == a.end() || (bp != b.end() && ap->first > bp->first)) {
         loc = bp->first ;
         v = f(0, bp++->second) ;
      } else if (bp == b.end() || (ap != a.end() && bp->first > ap->first)) {
         loc = ap->first ;
         v = f(ap++->second, 0) ;
      } else {
         loc = ap->first ;
         v = f(ap++->second, bp++->second) ;
      }
      if (v)
         r.push_back(make_pair(loc, v)) ;
   }
   return r ;
}
riv rot(const riv &a, ll k, ll n) {
   riv r = a ;
   for (auto &t : r)
      t.first = 1 + (t.first - 1 + n - k) % n ;
   sort(r.begin(), r.end()) ;
   return r ;
}
ostream& operator<<(ostream& os, const riv &r) {
   os << r.size() ;
   for (auto e : r)
      os << " " << e.first * e.second ;
   return os ;
}
int main() {
   ll n{}, k{} ;
   cin >> n >> k ;
   riv a = readriv() ;
   riv b = readriv() ;
   cout << compose(a, b, [](ll a, ll b){return sgn(a+b);}) << endl ;
   cout << compose(a, b, [](ll a, ll b){return a*b;}) << endl ;
   cout << rot(a, k, n) << endl ;
   cout << rot(b, k, n) << endl ;
}
