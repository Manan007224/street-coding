#include <bits/stdc++.h>
using namespace std;

int lastIndex(int input[], int size, int x){
  if(size==1){
    if(input[0]==x)
      return 0;
    else
      return -1;
  }
  else if(input[size-1]==x)
    return size-1;
  else
    return lastIndex(input, size-1, x);
}

int main(){
  int input[6] = {9,8,9,1,2,3};
  cout << "Last Index: " << lastIndex(input, 6, 7) << endl;
  return 0;
}
