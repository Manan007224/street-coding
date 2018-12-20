#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
int n, k ;
constexpr ll BAD = -1000000000000000000LL ;
ll tri(ll v) { return v * (v - 1) / 2 ; }
int main() {
   cin >> n >> k ;
   vector<int> v(n) ;
   v = vector<int>(n) ;
   vector<int> cnts(k+1) ;
   vector<vector<int> > cnts2 ;
   ll r{}, missing{} ;
   for (int i=0; i<n; i++) {
      cin >> v[i] ;
      if (v[i] > 0) {
         for (int j=0; j<v[i]; j++)
            cnts[j]++ ;
         r += cnts[v[i]] ;
      } else {
         missing++ ;
      }
      cnts2.push_back(cnts) ;
   }
   vector<ll> best(missing+1) ;
   vector<ll> nbest(missing+1) ;
   vector<ll> icnt(missing+1) ;
   for (int i=1; i<=missing; i++)
      best[i] = BAD ;
   for (int i=k; i>=1; i--) {
      int totnonz{} ;
      ll sinv{} ;
      for (int j=0; j<n; j++) {
         if (v[j])
            continue ;
         sinv += cnts2[j][i] ;
         sinv += (cnts[0]-cnts[i-1])-(cnts2[j][0]-cnts2[j][i-1]) ;
         icnt[++totnonz] = sinv ;
      }
      totnonz = 0 ;
      nbest[0] = 0 ;
      int curk = 0 ;
      int curleftnonz = 0 ;
      for (int j=0; j<n; j++) {
         if (v[j])
            continue ;
         int leftnonz = curleftnonz ;
         ll bestv{BAD} ;
         for (int k=curk; k<=j; k++) {
            if (v[k])
               continue ;
            ll t { best[leftnonz] - tri(totnonz-leftnonz+1) + icnt[totnonz+1] - icnt[leftnonz] } ;
            if (t < bestv)
               break ;
            if (t > bestv) {
               bestv = t ;
               curk = k ;
               curleftnonz = leftnonz ;
            }
            leftnonz++ ;
         }
         totnonz++ ;
         nbest[totnonz] = max(best[totnonz], bestv) ;
      }
      swap(best, nbest) ;
   }
   cout << r + tri(missing) + best[missing] << endl ;
}
