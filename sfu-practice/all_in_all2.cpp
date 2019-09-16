#include <bits/stdc++.h>
using namespace std;

void solve(string a, string b) {
  int j = 0;
  for(int i=0; i<b.length(); i++) {
    if(b[i] == a[j]) j++;
    if(j == a.length()) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main() {
  string a, b;
  while(cin >> a >> b) solve(a, b);
  return 0;
}