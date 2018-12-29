#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int solution(vector<int> &a) {
    int size = a.size();
    if(size==0) return 0;
    vector<int> os(size);
    vector<int> es(size);

    for(int i = 0; i < size; i++) {
      int oi = i;
      int ei = i;
        int ediff = INF;
        int odiff = INF;
        for(int j = i+1; j < size; j++) {
            if (a[j] > a[i] && ((a[j]-a[i]) < odiff)) {
                odiff = a[j] - a[i];
                oi = j;
            }
            if (a[j] < a[i] && ((a[i] - a[j]) < ediff)) {
                ediff = a[i] - a[j];
                ei = j;
            }
        }
        os[i] = oi;
        es[i] = ei;
    }
    os[size-1] = size-1;
    es[size-1] = size-1;
    int count = 0;
    for(int i = 0; i < size; i++) {
      bool odd = true;
      int j = i;
      int k;
      while(j != size - 1) {
        k = j;
        if (odd) j = os[j];
        else j = es[j];
        odd = !odd;
        if (k == j) break;
      }
      if (j == size - 1) count++;
    }
    return count;

}


int main() {
    vector<int> a = {10, 11, 14, 11, 10};
    vector<int> b={5,4,3,2,1};
    vector<int> c={1};
    cout<<solution(b)<<endl;
    return 0;
}