#include <bits/stdc++.h>
using namespace std;

int permut(int n){
  int count=n;
  for(int k=n-1;k>=1;k--)
    count=count*k;
  return count;
}

int permutations(string str, vector<string> &pt){
  if(str.length()==0){
    pt.push_back("");
    return 1;
  }
  int itr = permutations(str.substr(1), pt);
  vector<string> tp;
  tp=pt;
  for(int k=0;k<tp.size();k++)
    pt[k]=str.substr(0,1)+tp[k].substr(0);
  for(int i=1;i<str.length();i++){
    for(int j=0;j<tp.size();j++){
      pt.push_back(tp[j].substr(0,i)+str.substr(0,1)+tp[j].substr(i));
    }
  }
  return permut(str.length());
}

int returnPermutations(string input, string output[]){
   vector<string> tt;
   int ans = permutations(input, tt);
   for(int k=0;k<tt.size();k++)
    output[k]=tt[k];
   return ans;
}

int main(){
  string test = "adg";
  string output[10000];
  int ans = returnPermutations(test, output);
  return 0;
}
