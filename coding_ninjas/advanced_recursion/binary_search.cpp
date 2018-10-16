#include <bits/stdc++.h>
using namespace std;

int bs(int input[], int l, int r, int element){
  int m = (l+r)/2;
  if(l>r)
    return -1;
  else if(input[m]==element)
    return m;
  else if(element>input[m])
    return bs(input, m+1, r, element);
  else
    return bs(input, l, m-1, element);
}

int binarySearch(int input[], int size, int element) {
  return bs(input, 0, size-1, element);
}

int main(){
  int input[6] = {2,3,4,5,6,7};
  cout << binarySearch(input, 6, 3) << endl;
  return 0;
}
