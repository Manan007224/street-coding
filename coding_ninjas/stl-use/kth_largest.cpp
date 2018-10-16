#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v){
  for(int k=0;k<v.size();k++) cout << v[k] << endl;
}

void insert(vector<int> &arr, int num){
  arr.push_back(num);
  for(int i=arr.size()-1;i>1;i=i/2){
    if(arr[i]>arr[i/2])
      swap(arr[i], arr[i/2]);
    else
      break;
  }
}

void adjust_heap(vector<int> &arr){
  int sz = arr.size();
  int idx=0;
  while(idx <sz){
    int root = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;
    if((left<sz && arr[left]>arr[root]) && right>=sz)
      break;
    if((right<sz && arr[right]>arr[root]) && left>=sz)
      break;
    if((left<sz && arr[left]>arr[root]) || (right<sz && arr[right]>arr[root]))
      break;
    if(left<sz && arr[left]>arr[root])
      root = left;
    if(right<sz && arr[right]>arr[root])
      root = right;
    if(root!=idx){
      swap(arr[idx], arr[root]);
      idx = root;
    }
  }
}

vector<int> heap_sort(vector<int> &arr){
  vector<int> res;
  for(int i=arr.size()-1;i>=0;i--){
    swap(arr[0], arr[i]);
    res.push_back(arr[i]);
    arr.pop_back();
    adjust_heap(arr);
  }
  return res;
}

void kthLargest(vector<int> arr, int n, int k){
  vector<int> tp = arr;
  make_heap(tp.begin(), tp.end());
  vector<int> ans = heap_sort(tp);
  cout << "Ans" << endl;
  print(ans);
  //return tp[tp.size()-k];
}


int main(){
  vector<int> arr = {2, 6, 10, 11, 13, 4, 1, 20};
  //cout << kthLargest(arr, arr.size(), 4) << endl;
  kthLargest(arr, arr.size(), 4);
  return 0;
}
