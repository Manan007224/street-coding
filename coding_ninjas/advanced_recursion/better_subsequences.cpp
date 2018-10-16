#include <bits/stdc++.h>
using namespace std;

void subs(string tp1, string tp2){
  if(tp1.empty()){
    cout << tp2 << endl;
    return;
  }
  string str1 = tp1.substr(1);
  string str2 = tp2;
  string str3 = tp2 + tp1.substr(0,1);
  subs(str1, str2);
  subs(str1, str3);
}

void subsequence(string input){
  subs(input.substr(1), "");
  subs(input.substr(1), input.substr(0,1));
}

int main(){
  string str = "abc";
  subsequence(str);
  return 0;
}
