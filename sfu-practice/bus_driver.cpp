#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d ,r;
  while(cin >> n >> d >> r) {
    if(!n && !d && !r) break;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ovt = 0;
    for(int i=0; i<n; i++) {
      int t = a[i] + b[n-1-i];
      if(t > d) ovt += (t - d) * r;
    }
    cout << ovt << endl;
  }
  return 0;
}
