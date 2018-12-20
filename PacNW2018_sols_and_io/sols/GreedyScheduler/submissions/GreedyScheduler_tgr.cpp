#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
int main() {
   int N{}, C{} ;
   cin >> N >> C ;
   vector<int> v(N) ;
   for (int i=0; i<C; i++) {
      int ci{} ;
      cin >> ci ;
      int clerk = min_element(v.begin(), v.end()) - v.begin() ;
      if (i)
         cout << " " ;
      cout << (1+clerk) ;
      v[clerk] += ci ;
   }
   cout << endl ;
}
