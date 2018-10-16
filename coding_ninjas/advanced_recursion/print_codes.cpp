#include <bits/stdc++.h>
using namespace std;

vector<string> letters = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
"p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void code(string str, string left){
  if(left.length()==0){
    cout << str << endl;
    return;
  }
  int f = stoi(left.substr(0,1));
  code((str+letters[f]), left.substr(1));
  if(left.length()==2 && (stoi(left.substr(0,2))<=26)){
    int s = stoi(left.substr(0,2));
    code((str+letters[s]), left.substr(2));
  }
  if(left.length()>2 && (stoi(left.substr(0,2))<=26)){
    int s = stoi(left.substr(0,2));
    code((str+letters[s]), left.substr(2));
  }
}

void printAllPossibleCodes(string input){
  code("", input);
}

int main(){
  string str = "1123";
  printAllPossibleCodes(str);
  return 0;
}
