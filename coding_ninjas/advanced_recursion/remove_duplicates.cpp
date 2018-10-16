#include <bits/stdc++.h>
using namespace std;

void print(char *input){
  int k=0;
  while(input[k]!='\0'){
    cout << input[k] << endl;
    k++;
  }
}

void remove_duplicates(char *input, int nidx, int idx){
    if(input[idx+1]=='\0'){
      input[nidx] = input[idx];
      input[nidx+1] = '\0';
      return;
    }
    if(input[idx]==input[idx+1]){
      remove_duplicates(input, nidx, idx+1);
      return;
    }
    else{
      input[nidx] = input[idx];
      remove_duplicates(input, nidx+1, idx+1);
    }
}

void removeConsecutiveDuplicates(char *input) {
  remove_duplicates(input, 0, 0);
}

int main(){
  char * input = new char[6] {'a', 'a', 'b', 'a', 'a', '\0'};
  removeConsecutiveDuplicates(input);
  print(input);
  return 0;
}
