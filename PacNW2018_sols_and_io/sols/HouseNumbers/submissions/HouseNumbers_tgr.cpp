#include <iostream>
using namespace std ;
typedef long long ll ;
int main(int argc, char *argv[]) {
   int M ;
   cin >> M ;
   ll N = M ;
   ll sumall = M ;
   ll sumleft = M ;
   for (ll x=M+1; ; x++) {
      ll targ = 2 * sumleft + x ;
      while (sumall < targ)
         sumall += ++N ;
      if (sumall == targ) {
         cout << M << " " << x << " " << N << endl ;
         return 0 ;
      }
      sumleft += x ;
   }
}
