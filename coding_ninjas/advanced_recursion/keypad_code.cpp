#include <bits/stdc++.h>
using namespace std;

vector<string> letters = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad_code(int num, vector<string> &v){
  if(num==0){
    v.push_back("");
    return 1;
  }
  int new_num = num/10;
  int to_add = num%10;
  int count = keypad_code(new_num, v);
  string ltr = letters[to_add];
  vector<string> tp;
  for(int k=0;k<count;k++){
    tp.push_back(v[k]);
    v[k] = (v[k]+ltr[0]);
  }
  for(int i=1;i<ltr.length();i++){
    for(int j=0;j<count;j++){
      v.push_back(tp[j]+ltr[i]);
    }
  }
  return count*(ltr.length());
}

int keypad(int num, string output[]){
  vector<string> ans;
  int op = keypad_code(num, ans);
  for(int k=0;k<ans.size();k++) output[k] = ans[k];
  return op;
}

int main(){
  int n = 27;
  vector<string> ans;
  string output[12];
  //int c = keypad_code(n, ans);
  //for(auto it: ans) cout << it << endl;
  int aa = keypad(n, output);
  for(int k=0;k<12;k++) cout << output[k] << endl;
  return 0;
}
