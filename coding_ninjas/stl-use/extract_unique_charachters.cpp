#include<bits/stdc++.h>
using namespace std;

void print(vector<char> &v){
  for(int k=0;k<v.size();k++) cout << v[k] << endl;
}

char* uniqueChar(char *str){
  vector<char> ch;
  unordered_set<char> s;
  int i=0;
  while(str[i]!='\0'){
    if(s.find(str[i]) == s.end()){
      s.insert(str[i]);
      ch.push_back(str[i]);
    }
    i++;
  }
  char * result = new char[ch.size()];
  for(int k=0;k<ch.size();k++)
    result[k] = ch[k];
  return result;
}

int main(){
  char * str = new char[0] {};
  char * ans = uniqueChar(str);
  int i=0;
  while(ans[i]!='\0'){
    cout << ans[i] << endl;
    i++;
  }
  return 0;
}
