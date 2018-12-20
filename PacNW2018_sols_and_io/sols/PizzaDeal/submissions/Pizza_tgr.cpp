#include <iostream>
#include <math.h>
using namespace std ;
int main() {
   double A1, P1, R2, P2 ;
   cin >> A1 >> P1 >> R2 >> P2 ;
   if (A1 / P1 > M_PI * R2 * R2 / P2)
      cout << "Slice of pizza" << endl ;
   else
      cout << "Whole pizza" << endl ;
}
