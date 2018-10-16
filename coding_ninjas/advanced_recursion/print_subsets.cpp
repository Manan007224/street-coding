#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &tp1){
  for(int k=0;k<tp1.size();k++)
    cout << tp1[k] << " ";
  cout << endl;
}

void subs(vector<int> &tp1, vector<int> &tp2){
  if(tp2.size()==0){
    print(tp1);
    return;
  }
  vector<int> vt (tp2.begin()+1, tp2.end());
  vector<int> vt1 = tp1;
  vt1.push_back(tp2[0]);
  subs(tp1, vt);
  subs(vt1, vt);
}

void printSubsetsofArray(int input[], int size){
  vector<int> tp1;
  for(int k=0;k<size;k++)
    tp1.push_back(input[k]);
  vector<int> fs = {tp1[0]};
  vector<int> vt (tp1.begin()+1, tp1.end());
  vector<int> ep;
  subs(ep, vt);
  subs(fs, vt);
}

int main(){
  int input[3] = {15, 10, 12};
  printSubsetsofArray(input, 3);
  return 0;
}
