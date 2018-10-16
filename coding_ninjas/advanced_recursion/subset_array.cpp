#include <bits/stdc++.h>
using namespace std;

int sub(vector<int> ip, vector<vector<int>> &op){
  if(ip.size()==0){
    vector<int> tp = {0};
    op.push_back(tp);
    return 1;
  }
  int fs = ip[0];
  ip.erase(ip.begin());
  vector<int> tp = ip;
  int nc = sub(ip, op);
  for(int i=0;i<nc;i++){
    vector<int> vt = op[i];
    vt[0]+=1;
    vt.insert(vt.begin()+1,fs);
    op.push_back(vt);
  }
  return 2*nc;
}

int subset(int input[], int n, int output[][20]){
  vector<int> ip;
  for(int k=0;k<n;k++)
    ip.push_back(input[k]);
  vector <vector <int> > op;
  int ans = sub(ip, op);
  for(int k=0;k<op.size();k++){
    vector<int> tp=op[k];
    for(int i=0;i<tp.size();i++)
      output[k][i]=tp[i];
  }
  return ans;
}

int main(){
  vector<int> input = {1,3,4,2};

  return 0;
}
