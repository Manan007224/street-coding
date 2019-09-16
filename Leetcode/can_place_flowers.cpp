#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int k = flowerbed.size(), res = 0;
    if(k == 1) return flowerbed[0] >= n;
    for(int i=0; i<k-1; i++) {
      if(i==0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
        flowerbed[i] = 1, res++;
      }
      else if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
        flowerbed[i] = 1, res++;
      }
    }
    return res >= n;
  }
};

int main() {
	vector<int> v = {0,0,0,0,1};
	Solution sln;
	cout << sln.canPlaceFlowers(v, 1) << endl;
	return 0;
}