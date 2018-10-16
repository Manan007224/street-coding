#include <bits/stdc++.h>
using namespace std;

int count(int x, int y){
  if(x>y)
    return 0;
  if(x==y)
    return 1;
  int v = y-x;
  return (count(1, v) + count(2, v) + count(3, v));
}

int staircase(int n){
  int ans = count(1, n) + count(2, n) + count(3, n);
}

int main(){
  cout << staircase(4) << endl;
  return 0;
}
