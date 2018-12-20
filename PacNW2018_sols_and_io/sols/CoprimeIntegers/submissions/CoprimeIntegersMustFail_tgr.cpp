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
int isprime(int p) {
   if (p < 2)
      return 0 ;
   if (p < 4)
      return 1 ;
   if ((p & 1) == 0)
      return 0 ;
   for (int j=3; ; j+=2) {
      if (p % j == 0)
         return 0 ;
      if (j * j > p)
         return 1 ;
   }
}
int main() {
   int A, B, C, D ;
   cin >> A >> B >> C >> D ;
   int HI { min(B, D) } ;
   vector<int> primes ;
   vector<char> sf(HI+1) ;
   primes.push_back(2) ;
   for (int i=3; i<=HI; i += 2)
      if (isprime(i))
         primes.push_back(i) ;
   cout << incex(0, 1, 1, primes, A-1, B, C-1, D) << endl ;
}
