#include <iostream>
using namespace std ;
int main() {
   int N{}, hi{}, S{} ;
   cin >> N >> S ;
   for (int i=0; i<N; i++) {
      int v{} ;
      cin >> v ;
      hi = max(hi, v) ;
   }
   cout << (hi*S+999)/1000 << endl ;

}
