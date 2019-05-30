#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int heightChecker(vector<int>& heights) {
    int res = 0;
    vector<int> temp = heights;
    sort(temp.begin(), temp.end());
    for(int i=0; i<temp.size(); ++i) {
      if(heights[i] != temp[i]) ++res;
    }
    return res;
  }
};