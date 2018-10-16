#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v){
  for(int k=0;k<v.size();k++) cout << v[k] << endl;
}

vector<int> longestSubsequence(int *arr, int n){
	vector<int> sq;
  unordered_set<int> s;
  int max_len = 0;
  for(int i=0;i<n;i++)
    s.insert(arr[i]);
  for(int i=0;i<n;i++){
    int num = (arr[i]-1);
    if(s.find(num) == s.end()){
      vector<int> local_sq;
      int start = arr[i];
      while(s.find(start)!=s.end()){
        local_sq.push_back(start);
        start++;
      }
      if((start-arr[i])>max_len){
        max_len = start-arr[i];
        sq.clear();
        sq = local_sq;
      }
    }
  }
  return sq;
}

int main(){
  int * arr = new int[13] {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
  vector<int> ans;
  ans = longestSubsequence(arr, 13);
  int * arr1 = new int[7] {15, 13, 23, 21, 19, 11, 16};
  vector<int> ans1;
  ans1 = longestSubsequence(arr1, 7);
  cout << "result 1" << endl;
  print(ans);
  cout << "result 2" << endl;
  print(ans1);
  return 0;
}
