#include <bits/stdc++.h>
using namespace std;

int staircase(int num, vector<int> &dp){
  if(num<0)
    return 0;
  else if(dp[num]!=0)
    return dp[num];
  else{
    int st;
    if(num==0 || num==1)
      st=1;
    else
      st = staircase(num-1, dp) + staircase(num-2, dp) + staircase(num-3, dp);
    dp[num] = st;
    return st;
  }
}

int main(){
  vector<int> dp = {0,0,0,0,0};
  cout << staircase(4, dp) << endl;
  for(auto it: dp) cout << it << endl;
  return 0;
}
