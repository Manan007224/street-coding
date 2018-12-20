#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std ;
typedef long long ll ;
const ll MOD = 1'000'000'009 ;
int main(int argc, char *argv[]) {
   ll k {} ;
   int nb {} ;
   cin >> k >> nb ;
   vector<ll> r(k) ;
   vector<ll> cnt(k) ;
   cnt[0] = 1 ;
   ll oneb = k - 1 ;
   for (int b=0; b<nb; b++) {
      vector<ll> r2(k) ;
      vector<ll> cnt2(k) ;
      for (ll rem=0; rem<k; rem++) {
         long off { (rem+oneb)%k } ;
         cnt2[rem] = (cnt[rem] + cnt[off]) % MOD ;
         r2[rem] = (r[rem] + cnt[off] + r[off]) % MOD ;
      }
      swap(r, r2) ;
      swap(cnt, cnt2) ;
      oneb = 2 * oneb % k ;
   }
   cout << r[0] << endl ;
}
