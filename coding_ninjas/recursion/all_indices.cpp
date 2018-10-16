#include <bits/stdc++.h>
using namespace std;

void reverse_search(int input[], int size, int n, int idx, vector<int> &indices){
  if(idx<=size-1){
    if(input[idx]==n)
      indices.push_back(idx);
    reverse_search(input, size, n, idx+1, indices);
  }
}

vector<int> allIndexes(int input[], int size, int x){
  vector<int> indices;
  reverse_search(input, size, x, 0, indices);
  return indices;
}

int main(){
  int input[5] = {9,8,10,8,8};
  vector<int> output = allIndexes(input, 5, 1);
  for(int k=0;k<output.size();k++) cout << output[k] << endl;
  return 0;
}
