#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &tp1){
  for(int k=0;k<tp1.size();k++)
    cout << tp1[k] << " ";
  cout << endl;
}

bool check_sum(vector<int> &tp, int target){
  int sum = 0;
  for(int k=1;k<tp.size();k++)
    sum+=tp[k];
  return (sum==target);
}

int sub(vector<int> ip, vector<vector<int>> &op, vector<vector<int>> &op1, int target){
  if(ip.size()==0){
    vector<int> tp = {0};
    op.push_back(tp);
    return 1;
  }
  int fs = ip[0];
  ip.erase(ip.begin());
  vector<int> tp = ip;
  int nc = sub(ip, op, op1, target);
  for(int i=0;i<nc;i++){
    vector<int> vt = op[i];
    vt[0]+=1;
    vt.insert(vt.begin()+1,fs);
    op.push_back(vt);
    if(check_sum(vt, target))
      op1.push_back(vt);
  }
  return 2*nc;
}

int subsetSumToK(int input[], int n, int output[][50], int k){
  vector<int> ip;
  for(int k=0;k<n;k++)
    ip.push_back(input[k]);
  vector <vector <int> > op;
  vector <vector <int> > op1;
  int ans = sub(ip, op, op1, k);
  for(int k=0;k<op1.size();k++){
    vector<int> tp=op1[k];
    for(int i=0;i<tp.size();i++)
      output[k][i]=tp[i];
  }
  return ans;
}

void combinationSum2(vector<int>& candidates, int target) {
  vector <vector <int> > op;
  vector <vector <int> > op1;
  int ans = sub(candidates, op, op1, target);
  for(int k=0;k<op1.size();k++)
      print(op1[k]);
  // return op1;
}


int main(){
  vector<int> cdn = {2,5,2,1,2};
  combinationSum2(cdn, 5);
  return 0;
}
