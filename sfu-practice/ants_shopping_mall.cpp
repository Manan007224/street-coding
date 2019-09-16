#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

void debug(vii g){
  for(auto nn: g) 
    for(auto n: nn) cout << n << " "; cout << endl;  
}

int main() {
  int t; cin >> t;
  for(int tt = 0; tt < t; tt++) {
    int r, c; cin >> r >> c;
    vii g(r, vi(c)), nr(r, vi(c));
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%1d", &g[i][j]);
    
    for(int i=0; i<r; i++) {
      int last = INT_MAX;
      for(int j=0; j<c; j++) {
        if(g[i][j] == 0) last = j;
        else if(last == INT_MAX) nr[i][j] = last;
        else nr[i][j] = j-last;
      }
      last = INT_MAX;
      for(int j=c-1; j>=0; j--) {
        if(g[i][j] == 0) last = j;
        if(last != INT_MAX) nr[i][j] = min(nr[i][j], last-j);
      }
    }
    int res = INT_MAX;
    for(int i=0; i<c; i++) {
      bool ps = 1;
      int moves = 0;
      for(int row=0; row<r; row++) {
        if(nr[row][i] == INT_MAX) {
          ps = 0;
          break;
        }
        moves += nr[row][i];
      }
      if(ps) res = min(moves, res);
    }
    cout << "Case " << tt << ":" ;
    if(res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
  }
  return 0;
}