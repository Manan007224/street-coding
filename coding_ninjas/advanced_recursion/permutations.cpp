#include <bits/stdc++.h>
using namespace std;

void permutations(string str, int start, int end){
  if(start==end){
    cout << str << endl;
    return;
  }
  for(int k=start;k<end;k++){
    string temp = str;
    swap(temp[start], temp[k]);
    permutations(temp, start+1, end);
  }
}

void printPermutations(string input){
	permutations(input, 0, input.length());
}

int main(){
  printPermutations("abc");
  return 0;
}
