#include <bits/stdc++.h>
using namespace std;

void print(int input[], int size){
  for(int i=0;i<size;i++)
    cout << input[i] << endl;
}

void sp(int input[], int left, int right){
  for(int i=left;i<=  right;i++) cout << input[i] << " ";
  cout << endl;
}

void merge(int input[], int left, int middle, int right){
  int tp1 = middle-left+1;
  int tp2 = right-middle;
  int la[tp1], lr[tp2];
  for(int i=0;i<tp1;i++)
    la[i] = input[left+i];
  for(int j=0;j<tp2;j++)
    lr[j] = input[middle+1+j];
  int i=0; int j=0; int k=left;
  while(i<tp1 && j<tp2){
    if(la[i]<=lr[j])
      input[k++] = la[i++];
    else
      input[k++] = lr[j++];
  }
  while(i<tp1)
    input[k++] = la[i++];
  while(j<tp2)
    input[k++] = lr[j++];
}

void msort(int input[], int left, int right){
  if(left<right){
    int middle = left+(right-left)/2;
    msort(input, left, middle);
    //sp(input, left, right);
    msort(input, middle+1, right);
    merge(input, left, middle, right);
  }
}

void mergeSort(int input[], int size){
  msort(input, 0, size-1);
}

int main(){
  int input[4] = {4, 1, 3, 2};
  mergeSort(input, 4);
  //print(input, 4);
  return 0;
}
