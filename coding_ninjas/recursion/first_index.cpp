#include <bits/stdc++.h>
using namespace std;

int reverse_search(int input[], int size, int n, int idx){
  if(idx==size-1){
    if(input[idx]==n)
      return idx;
    else
      return -1;
  }
  else if(input[idx]==n)
    return idx;
  else
    reverse_search(input, size, n, idx+1);
}

int firstIndex(int input[], int size, int x){
  return reverse_search(input, size, x, 0);
}

int main(){
  int input[5] = {9,8,10,8,9};
  cout << "Index: " << firstIndex(input, 5, 1) << endl;
  return 0;
}
