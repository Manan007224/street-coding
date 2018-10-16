#include <bits/stdc++.h>
using namespace std;

int sum(int input[], int n){
  if(n==1)
    return input[0];
  else
    return input[n-1] + sum(input, n-1);
}

int main(){
  int input[1] = {0};
  cout << "Sum: " << sum(input, 1) << endl;
  return 0;
}
