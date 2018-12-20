#include <iostream>
#include <string>
using namespace std ;
const int N = 23 ;
int n ;
int cache[N<<N] ;
int recur(const string &a, const string &b, int at, int prev, int mask) {
   if (at == n)
      return -1 ;
   int k = (prev<<n)+mask ;
   if (cache[k] >= 0)
      return cache[k] ;
   int r = n ;
   for (int i=0; i<n; i++)
      if (a[at] == b[i] && ((mask >> i) & 1) == 0) {
         int t = recur(a, b, at+1, i, mask|(1<<i)) ;
         if (i == prev + 1 && mask != 0)
            r = min(r, t) ;
         else
            r = min(r, t+1) ;
      }
   cache[k] = r ;
   return r ;
}
int main() {
   string s1, s2 ;
   cin >> s1 >> s2 ;
   n = s1.size() ;
   for (int i=0; i<(n<<n); i++)
      cache[i] = -1 ;
   cout << recur(s1, s2, 0, 0, 0) << endl ;
}
