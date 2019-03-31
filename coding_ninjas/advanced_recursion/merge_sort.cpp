#include <bits/stdc++.h>
using namespace std;

void merge(int ip[], int l, int m, int r){
  int tp1 = m-l+1;
  int tp2 = r-m;
  int la[tp1], lr[tp2];
  for(int i=0;i<tp1;i++) la[i]=ip[l+i];
  for(int j=0;j<tp2;j++) lr[j]=ip[m+1+j];
  int i=0; int j=0; int k=l;
  while(i<tp1&&j<tp2){
    if(la[i]<=lr[j]) ip[k++]=la[i++];
    else ip[k++]=lr[j++];
  }
  while(i<tp1) ip[k++]=la[i++];
  while(j<tp2) ip[k++]=lr[j++];
}

void sort(int ip[], int l, int r){
  if(l<r){
    int m = l+(r-l)/2;
    sort(ip,l,m);
    sort(ip,m+1,r);
    merge(ip,l,m,r);
  }
}

int main(){
  int ip[4] = {4, 1, 3, 2};
  msort(ip,0,4);
  return 0;
}

// cout << "########################## START ##########################" << endl;
      // for(auto a: left) cout << a << " ";
      // cout << endl;
      // for(auto b: right) cout << b << " ";
      // cout << endl;
      // cout << ivn << endl;
      // cout << "########################## STOP ##########################" << endl;