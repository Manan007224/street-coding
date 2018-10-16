#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &tp1){
  for(int k=0;k<tp1.size();k++)
    cout << tp1[k] << " ";
  cout << endl;
}

bool check_sum(vector<int> &tp, int target){
  int sum = 0;
  for(int k=0;k<tp.size();k++)
    sum+=tp[k];
  return (sum==target);
}

void subs(vector<int> &tp1, vector<int> &tp2, int target){
  if(tp2.size()==0){
    if(check_sum(tp1, target))
      print(tp1);
    return;
  }
  vector<int> vt (tp2.begin()+1, tp2.end());
  vector<int> vt1 = tp1;
  vt1.push_back(tp2[0]);
  subs(tp1, vt, target);
  subs(vt1, vt, target);
}

void printSubsetSumToK(int input[], int size, int k){
  vector<int> tp1;
  for(int k=0;k<size;k++)
    tp1.push_back(input[k]);
  vector<int> fs = {tp1[0]};
  vector<int> vt (tp1.begin()+1, tp1.end());
  vector<int> ep;
  subs(ep, vt, k);
  subs(fs, vt, k);
}

int main(){
  int input[4] = {1,3,4,2};
  printSubsetSumToK(input, 4, 5);
  return 0;
}
