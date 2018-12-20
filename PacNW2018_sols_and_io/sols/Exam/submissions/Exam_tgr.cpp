#include <iostream>
#include <string>
using namespace std ;
int main() {
   int fs{} ;
   cin >> fs ;
   string myanswers{}, friendanswers{} ;
   cin >> myanswers >> friendanswers ;
   int same{}, n{static_cast<int>(myanswers.size())} ;
   for (int i=0; i<n; i++)
      if (myanswers[i] == friendanswers[i])
         same++ ;
   cout << min(same, fs) + min(n-same, n-fs) << endl ;
}
