#include <bits/stdc++.h>
using namespace std;

void replaceCharacter(char *input, char c1, char c2){
  if(input[0]!='\0'){
    if(*input==c1){
      *input=c2;
    }
    replaceCharacter(input+1, c1, c2);
  }
}

int main(){
  char * input = new char[6] {'M', 'a', 'n', 'a', 'n', '\0'};
  replaceCharacter(input, 'a', 'x');
  for(int k=0;k<5;k++) cout << input[k] << endl;
  return 0;
}
