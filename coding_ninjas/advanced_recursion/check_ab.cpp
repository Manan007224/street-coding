#include <bits/stdc++.h>
using namespace std;

bool check(string str){
  if(str.empty())
    return true;
  else{
    string tp1 = str[0]=='a' ? str.substr(0,1) : str.substr(0,2);
    if(tp1=="a" && str.substr(1).empty())
      return check(str.substr(1));
    else if(tp1=="a" && str[1]=='a')
      return check(str.substr(1));
    else if(tp1=="a" && str[1]=='b' && str[2]=='b')
      return check(str.substr(1));
    else if(tp1=="bb" && str.substr(2).empty())
      return check(str.substr(2));
    else if(tp1=="bb" && str[2]=='a')
      return check(str.substr(2));
    else
      return false;
  }
}

bool checkAB(char input[]){
  string str;
  int k=0;
  while(input[k]!='\0'){
    str+=input[k];
    k++;
  }
  if(str.length()>=1 && str[0]=='a')
    return check(str.substr(1));
  else
    return false;
}

int main(){
  char input[5] = {'a', 'b', 'b', 'a', '\0'};
  cout << checkAB(input) << endl;
}
