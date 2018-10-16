#include<bits/stdc++.h>
using namespace std;

int* stockspan(int *price, int size){
  int * stocks = new int[size];
  stack<int> s;
  s.push(0);
  stocks[0] = 1;
  for(int i=1; i<size; i++){
    while(!s.empty() && (price[s.top()]<price[i]))
      s.pop();
    if(!s.empty())
      stocks[i] = (i-s.top());
    else
      stocks[i] = i+1;
    s.push(i);
  }
  return stocks;
}

int main(){
  int * prices = new int[7] {100, 80, 60, 70, 60, 75, 85};
  int * result = stockspan(prices, 7);
  for(int k=0;k<7;k++) cout << result[k] << endl;
  return 0;
}
