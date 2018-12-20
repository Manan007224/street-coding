#include <iostream>
#include <algorithm>
using namespace std ;
int cnts[256] ;
int main() {
   for (int i=0; i<5; i++) {
      char c{} ;
      cin >> c ;
      cnts[c]++ ;
      cin >> c ;
   }
   cout << *(max_element(&cnts[0], &cnts[128])) << endl ;
}
