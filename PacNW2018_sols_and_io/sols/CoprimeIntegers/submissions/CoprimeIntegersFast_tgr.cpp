#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
ll incex(int at, int prod, int par, const vector<int> &p, int a, int b, int c, int d) {
   ll r { par * (b / prod - a / prod) * (ll)(d / prod - c / prod) } ;
   int lim = min(b, d) / prod ;
   for (int i=at; i<p.size() && p[i] <= lim; i++)
      r += incex(i+1, prod*p[i], -par, p, a, b, c, d) ;
   return r ;
}
int main() {
   int A, B, C, D ;
   cin >> A >> B >> C >> D ;
   int HI { min(B, D) } ;
   vector<int> primes ;
   vector<char> sf(HI+1) ;
   primes.push_back(2) ;
   for (ll i=3; i<=HI; i += 2)
      if (sf[i] == 0) {
         primes.push_back(i) ;
         sf[i] = 1 ;
         if (HI / i >= i)
            for (ll j=i*i; j<=HI; j += 2*i)
               sf[j] = 1 ;
      }
   cout << incex(0, 1, 1, primes, A-1, B, C-1, D) << endl ;
}
