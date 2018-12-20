#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
vector<int> sf ;
ll incex(int at, int prod, int par, const vector<int> &p, int lo, int hi) {
   ll r { hi / prod - lo / prod } ;
   if (par)
      r = - r ;
   for (int i=at; i<p.size(); i++)
      r += incex(i+1, prod*p[i], !par, p, lo, hi) ;
   return r ;
}
int main() {
   int A, B, C, D ;
   cin >> A >> B >> C >> D ;
   int HI { max(B, D) } ;
   sf.resize(HI+1) ;
   sf[1] = 1 ;
   for (ll i=2; i<=HI; i += 2)
      sf[i] = 2 ;
   for (ll i=3; i<=HI; i += 2)
      if (sf[i] == 0) {
         sf[i] = i ;
         if (HI / i >= i)
            for (ll j=i*i; j<=HI; j += 2*i)
               if (sf[j] == 0)
                  sf[j] = i ;
      }
   ll r { 0 } ;
   vector<int> primes ;
   for (int a=A; a<=B; a++) {
      int t { a } ;
      primes.clear() ;
      while (t > 1) {
         int p { sf[t] } ;
         primes.push_back(p) ;
         while (t % p == 0)
            t /= p ;
      }
      r += incex(0, 1, 0, primes, C-1, D) ;
   }
   cout << r << endl ;
}
