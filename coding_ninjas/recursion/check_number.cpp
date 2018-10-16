#include <bits/stdc++.h>
using namespace std;

bool checkNumber(int input[], int size, int n){
  if(size==1){
    if(n==input[0])
      return true;
    else
      return false;
  }
  else if(input[size-1]==n)
    return true;
  else
    return checkNumber(input, size-1, n);
}

int main(){
  int input[3] = {9,8,5};
  cout << checkNumber(input, 3, 1) << endl;
  return 0;
}
