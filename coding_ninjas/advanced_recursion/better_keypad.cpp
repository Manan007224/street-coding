#include <bits/stdc++.h>
using namespace std;

vector<string> letters = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad_code(int num, string tp1){
  if(num==0){
    cout << tp1 << endl;
    return;
  }
  string ltr = letters[num%10];
  int further = num/10;
  for(int i=0;i<ltr.length();i++){
    keypad_code(further, (ltr[i]+tp1));
  }
}

void printKeypad(int num){
  keypad_code(num, "");
}

int main(){
  printKeypad(27);
  return 0;
}
