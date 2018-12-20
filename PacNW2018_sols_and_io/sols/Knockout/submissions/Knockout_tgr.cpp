#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std ;
constexpr int HIDIG = 9 ;
int val[2][1<<HIDIG] ;
int dsum[2][1<<HIDIG] ;
double dval[2][1<<HIDIG] ;
int movesel[2][1<<HIDIG][13] ;
constexpr double NEGINF = -1e20 ;
int main(int argc, char *argv[]) {
   cout << setprecision(5) << fixed ;
   for (int mi=0; mi<2; mi++) {
      int m { -1 + 2 * mi } ;
      int hidig { 1 } ;
      for (int i=1; (i>>HIDIG)==0; i++) {
         if (i >> hidig)
            hidig++ ;
         int k { i - (1 << (hidig - 1)) } ;
         val[mi][i] = 10 * val[mi][k] + m * hidig ;
         dsum[mi][i] = dsum[mi][k] + hidig ;
         double mval[13] ;
         for (int dr=2; dr<=12; dr++) {
            mval[dr] = NEGINF ;
            movesel[mi][i][dr] = -1 ;
         }
         for (int j=0; j<i; j = ((j | ~i) + 1) & i) {
            int dd { dsum[mi][i] - dsum[mi][j] } ;
            if (dd >= 2 && dd <= 12) {
               if (mval[dd] < dval[mi][j]) {
                  mval[dd] = dval[mi][j] ;
                  movesel[mi][i][dd] = j ;
               } else if (mval[dd] == dval[mi][j]) {
                  cout << "Warn:  duplicated val" << endl ;
               }
            }
         }
         double s { 0 } ;
         for (int dr=2; dr<=12; dr++) {
            int pr { min(dr-1, 13-dr) } ;
            if (mval[dr] == NEGINF) // have to stop here
               s += pr * val[mi][i] ;
            else
               s += pr * mval[dr] ;
         }
         dval[mi][i] = s / 36.0 ;
      }
   }
   int v {} ;
   int d1, d2 ;
   cin >> v >> d1 >> d2 ;
   int ivv { v } ;
   int dd { d1 * 10 + d2 } ;
   int vv { 0 } ;
   while (v) {
      vv |= 1 << (v % 10 - 1) ;
      v /= 10 ;
   }
   int dr { 0 } ;
   while (dd) {
      dr += dd % 10 ;
      dd /= 10 ;
   }
   for (int mi=0; mi<2; mi++) {
      int mb = movesel[mi][vv][dr] ;
      if (mb < 0) {
         cout << "-1" << " " << (double)ivv ;
      } else {
         mb = vv - mb ;
         for (int i=1; i<=HIDIG; i++)
            if ((mb >> (i - 1)) & 1)
               cout << i ;
         cout << " " << fabs(dval[mi][movesel[mi][vv][dr]]) ;
      }
      cout << endl ;
   }
}
