#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std ;
typedef long long ll ;
/* prime sieve */
vector<char> sf ;
vector<ll> primes ;
int main(int argc, char *argv[]) {
   ll HI {} ;
   cin >> HI ;
   sf.resize(HI+1) ;
   sf[1] = 1 ;
   for (ll i=2; i<=HI; i += 2)
      sf[i] = 2 ;
   primes.push_back(2) ;
   for (ll i=3; i<=HI; i += 2)
      if (sf[i] == 0) {
         primes.push_back(i) ;
         sf[i] = i ;
         if (HI / i >= i)
            for (ll j=i*i; j<=HI; j += 2*i)
               sf[j] = 1 ;
      }
   ll steps { 0 } ;
   size_t gtop { primes.size() - 1 } ;
   while (HI > 3) {
      while (primes[gtop] > HI)
         gtop-- ;
      size_t bot { 0 } ;
      size_t top { gtop } ;
      while (primes[bot] + primes[top] != HI)
         if (primes[bot] + primes[top] > HI)
            top-- ;
         else
            bot++ ;
//    cout << primes[bot] << " + " << primes[top] << " = " << HI << endl ;
      HI = primes[top] - primes[bot] ;
      steps++ ;
   }
   cout << steps << endl ;
}
