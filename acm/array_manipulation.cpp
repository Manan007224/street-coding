#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  long int n, m;
  cin >> n >> m;
  vector<LL> vec(n+1);
  LL int a, b, val;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> val;
    vec[a] += val;
    if( b < n ) vec[b+1] -= val;
  }
  long int x = 0;
  long int max = 0;
  for(int i = 1; i <= n; i++){
    x = x + vec[i];
    max = max(x, max);
  }
  cout << max << endl;
  return 0;
}