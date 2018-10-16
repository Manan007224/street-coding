#include <bits/stdc++.h>
using namespace std;

vector<string> letters = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
"p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void print(vector<string> &tp){
  for(int k=0;k<tp.size();k++)
    cout << tp[k] << endl;
}

int code(string s1, vector<string> &op){
  if(s1.length()==0){
    op.push_back(" ");
    return 1;
  }
  int f = stoi(s1.substr(0,1));
  int s;
  int a1 = code(s1.substr(1), op);
  int a2=0;
  for(int i=0;i<a1;i++){
    op[op.size()-1-i] = letters[f]+op[op.size()-i-1];
  }
  if(s1.length()==2 && (stoi(s1.substr(0,2))<=26)){
    a2 = code("0", op);
    s = stoi(s1.substr(0,2));
  }
  if(s1.length()>2 && (stoi(s1.substr(0,2))<=26)){
    a2 = code(s1.substr(2), op);
    s = stoi(s1.substr(0,2));
  }
  for(int i=0;i<a2;i++){
    op[op.size()-i-1]=letters[s]+op[op.size()-i-1];
  }
  return a1+a2;
}

int getCodes(string input, string output[10000]){
  vector<string> op;
  int ans = code(input, op);
  for(int k=0;k<op.size();k++){
    output[k]=op[k];
  }
  return ans;
}

int main(){
  string str = "1123";
  vector<string> op;
  int ans = code(str, op);
  string output[10000];
  cout << getCodes(str, output) << endl;
  return 0;
}
