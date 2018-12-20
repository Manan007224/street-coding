#include <iostream>
#include <vector>
using namespace std ;
int main() {
   int n{} ;
   cin >> n ;
   vector<int> a(n), b(n) ;
   for (int i=0; i<n; i++)
      cin >> a[i] >> b[i] ;
   for (int i=n; i>=0; i--) {
      int cnt = 0 ;
      for (int j=0; j<n; j++)
         if (a[j] <= i && i <= b[j])
            cnt++ ;
      if (cnt == i) {
         cout << cnt << endl ;
         return 0 ;
      }
   }
   cout << -1 << endl ;
} 
